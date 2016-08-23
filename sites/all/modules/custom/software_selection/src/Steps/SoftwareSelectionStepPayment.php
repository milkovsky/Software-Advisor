<?php

/**
 * @file Form step for payment.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepBase;

/**
 * Investment form payment step.
 */
class SoftwareSelectionStepPayment extends SoftwareSelectionStepBase {

  /**
   * Payment method data mapping.
   *
   * @var array
   *   Maps payment method data keys to user info fields.
   */
  protected $userInfoMapping = array(
    'account_owner' => 'field_user_account_owner',
    'iban' => 'field_user_iban',
    'bic' => 'field_user_bic',
  );

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Payment');
  }

  /**
   * {@inheritdoc}
   */
  public function getStepId() {
    return 'invest-step-payment';
  }

  /**
   * {@inheritdoc}
   */
  public function getSubmitNextLabel() {
    return $this->isRetryPage() ? t('Pay now') : t('Invest now');
  }

  /**
   * Returns whether the form is shown on the retry page.
   *
   * @return bool
   */
  protected function isRetryPage() {
    return arg(2) == 'retry';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = $this->addDefaultForm($form, $form_state);

    // After payment selection the form is re-loaded and the selected payment
    // has been written to form state. In this case we need to take the payment
    // as selected and written into form state always.
    if (!empty($form_state['payment'])) {
      $this->state->payment = $form_state['payment'];
    }
    // Pick up a pre-existing payment from the investment state or prepare a
    // new one.
    $payment = $this->preparePayment($form, $form_state);

    $project_wrapper = $this->state->project->getWrapper();
    if (!isset($form_state['is_retry'])) {
      $form_state['is_retry'] = $this->isRetryPage();
    }

    // Handle cases where the payment has been completed, but the user comes
    // back.
    $payment_state = $payment->getStatus()->status;
    if (payment_status_is_or_has_ancestor($payment_state, WIRECARD_PAYMENT_STATUS_APPROVED) ||
      payment_status_is_or_has_ancestor($payment_state, PAYMENT_STATUS_PENDING) ||
      payment_status_is_or_has_ancestor($payment_state, PAYMENT_STATUS_SUCCESS)
    ) {
      drupal_goto('invest/' . $this->state->project->node->nid . '/success');
    }
    elseif (!$form_state['is_retry'] &&
      (payment_status_is_or_has_ancestor($payment_state, WIRECARD_PAYMENT_STATUS_MAX_RETRIES) ||
      payment_status_is_or_has_ancestor($payment_state, PAYMENT_STATUS_FAILED))
    ) {
      drupal_goto('payment/' . $payment->pid . '/retry');
    }

    // Limit payment methods according to list of allowed ones in the project.
    $payment_ids = array();
    foreach ($project_wrapper->field_payment_methods as $delta => $method_name) {
      if ($payment_id = n1000_payment_method_get_id_by_name($method_name->value())) {
        $payment_ids[] = $payment_id;
      }
    }

    // Embed payment form and hide unnecessary elements.
    $form_info = payment_form_embedded($form_state, $payment, $payment_ids);
    $form['payment'] = $form_info['elements'];
    $form['payment']['payment_line_items']['#access'] = FALSE;
    $form['payment']['payment_status']['#access'] = FALSE;

    if ($form_state['is_retry']) {
      $form['payment']['payment_method']['#access'] = !payment_status_is_or_has_ancestor($payment->getStatus()->status, PAYMENT_STATUS_NEW);
      $form['#action'] = url(current_path());
    }

    $form = $this->prepopulatePaymentFormWithUserDefaults($form, $form_state);

    // Add selector for wirecard to detect submit button.
    $form['#attached']['js'][] = array(
      'data' => array(
        'wirecardPaymentSubmitSelector' => 'input:submit:visible:last',
      ),
      'type' => 'setting',
    );
    $form = $this->buildButtons($form, $form_state);

    // Disable ajax in the last step as payment my trigger an off-site redirect
    // which does not work so nice during ajax requests...
    unset($form['actions']['submit-step']['#ajax']);
    // But because of that errors might be shown at the top of the page. So
    // fix them to be shown on top of this form.
    $form['messages'] = array(
      '#theme' => 'status_messages',
      '#weight' => -5000
    );
    // @todo: Re-scrollto form also.
    return $form;
  }

  /**
   * Helper function; get payment from state or creates a new one.
   *
   * @param array $form
   *   Form array.
   * @param array $form_state
   *   Form state array.
   *
   * @return \Payment
   *   Payment object.
   */
  protected function preparePayment(array $form, array $form_state) {
    if (!empty($this->state->payment)) {
      return $this->state->payment;
    }
    else {
      $tmt_investment = TmtInvestment::create($this->state->software_selection);
      $amount = $tmt_investment->getAmount();
      $project = $this->state->project->node;

      /** @var EntityStructureWrapper $investorAddress */
      $investorAddress = $tmt_investment->getWrapper()->get('field_investment_user_info')->get('field_user_address');
      $investor = trim($investorAddress->get('first_name')->value() . ' ' . $investorAddress->get('last_name')->value());

      $payment = new Payment(array(
        'context' => 'n1000_payment',
        'context_data' => array(
          'project_id' => $project->nid,
          // Investment id will be completed during submit.
          'investment_id' => NULL,
        ),
        'currency_code' => 'EUR',
        'description' => t('Investment from !investor for the !title project', array('!investor' => $investor, '!title' => $project->title)),
        'finish_callback' => 'n1000_payment_finish',
      ));
      $payment->setLineItem(new PaymentLineItem(array(
        'amount' => $amount,
        'description' => t('Investment from !investor for the !title project', array('!investor' => $investor, '!title' => $project->title)),
        'name' => 'investment',
        'quantity' => 1,
      )));
      $this->state->payment = $payment;
    }
    return $payment;
  }

  /**
   * Helper function; pre-populates the form with user data for payment method.
   *
   * @return array
   *   The modified form.
   */
  protected function prepopulatePaymentFormWithUserDefaults($form, array &$form_state) {
    $account = entity_metadata_wrapper('user', $this->state->user);
    $entity = $account->field_investment_user_info->value();

    // Pre-populate form state with user data by writing it into form state.
    // Payment methods will pick it up from there. We cannot write directly
    // into the values as they are cleared in the beginning of the form
    // build. So do so in a process callback.
    #$form['#process'][] = 'tmt_invest_form_set_form_values_process';
    $form['#tmt_custom_values'] = array();

    foreach ($this->userInfoMapping as $payment_key => $user_field) {
      if (!empty($entity->{$user_field}[LANGUAGE_NONE][0]['value'])) {
        $form['#tmt_custom_values'][$payment_key] = $entity->{$user_field}[LANGUAGE_NONE][0]['value'];
      }
    }
    $investment = $this->state->software_selection;
    $investment->field_inv_auftragsnummer[LANGUAGE_NONE][0]['value'] = TmtInvestment::create($investment)
      ->generateOrderNumber();
    // Save investment to generate investment ID for the Auftragsnummer.
    $investment->save();
    return $form;
  }

  /**
   * Helper function; saves payment form user details for later use.
   */
  protected function savePaymentFormUserDefaults($form, array &$form_state) {
    $account = entity_metadata_wrapper('user', $this->state->user);
    $user_collection = $account->field_investment_user_info->value();
    $payment = $this->state->payment;

    foreach ($this->userInfoMapping as $payment_key => $user_field) {
      if (!empty($payment->context_data[$payment_key])) {
        $user_collection->{$user_field}[LANGUAGE_NONE][0]['value'] = $payment->context_data[$payment_key];
      }
    }
    $user_collection->save();

    // Save it to the investment also, but skip saving changes as it will be
    // saved later anyway.
    $investment = entity_metadata_wrapper('while', $this->state->software_selection);
    $investment_collecton = $investment->field_investment_user_info->value();
    foreach ($this->userInfoMapping as $payment_key => $user_field) {
      if (!empty($payment->context_data[$payment_key])) {
        $investment_collecton->{$user_field}[LANGUAGE_NONE][0]['value'] = $payment->context_data[$payment_key];
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {
    // Payment element handles validation.
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    // Be sure to save the payment of this form into the investment state.
    if (!empty($form_state['payment'])) {
      $this->state->payment = $form_state['payment'];
    }
    $payment = $this->state->payment;
    $investment = $this->state->software_selection;

    $this->savePaymentFormUserDefaults($form, $form_state);
    // Save the payment so we can reference it in the investment also.
    entity_save('payment', $payment);
    $this->updateInvestmentFromPayment();
    $investment->label = 'Investment for "' . $this->state->project->node->title . '" project';
    $investment->save();

    // Save investment id in the payment context.
    $payment->context_data['investment_id'] = $investment->id;

    // Execute payment after all the changes, because execution might contain
    // a redirect. Not that all custom payment finish logic is handled in
    // n1000_payment_payment_pre_finish().

    // As the redirect skips the final step form logic also, make sure to save
    // investment state also.
    $this->controller->saveStateData();

    $payment->execute();
  }

  /**
   * Updates investment payment data from payment entity.
   */
  protected function updateInvestmentFromPayment() {
    // Update payment data in the investment.
    $investment = $this->state->software_selection;
    $investment->field_inv_payment[LANGUAGE_NONE][0]['target_id'] = $this->state->payment->pid;
    // Map payment and investment fields.
    $payment_investment_mapping = array(
      'account_owner' => 'field_inv_kontoinhaber',
      'iban' => 'field_inv_iban',
      'bic' => 'field_inv_bic',
    );
    foreach ($this->state->payment->context_data as $key => $value) {
      if (!empty($payment_investment_mapping[$key])) {
        $investment->{$payment_investment_mapping[$key]}[LANGUAGE_NONE][0]['value'] = $value;
      }
    }
  }

}
