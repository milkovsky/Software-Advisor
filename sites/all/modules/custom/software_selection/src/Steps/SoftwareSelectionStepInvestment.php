<?php

/**
 * @file
 * Form step for main investment choices and confirmations.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepEntityForm;

/**
 * Investment form risk investment step.
 */
class SoftwareSelectionStepInvestment extends SoftwareSelectionStepEntityForm {

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_inv_businessplan',
    'field_inv_investition',
    'field_inv_reason',
    'field_inv_genussrecht',
    'field_inv_nachrangdarlehen',
    'field_inv_gesellschaftervertrag',
    'field_inv_treuhand_verwaltung',
    'field_inv_agreements',
    'field_inv_pieces_reference',
  );

  /**
   * {@inheritdoc}
   */
  protected $entityType = 'while';

  /**
   * {@inheritdoc}
   */
  public function getEntity() {
    return $this->state->software_selection;
  }

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Investment');
  }

  /**
   * {@inheritdoc}
   */
  public function getStepId() {
    return 'invest-step-investment';
  }

  /**
   * {@inheritdoc}
   */
  public function getSubmitLabel() {
    return t('Save and continue');
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $project_wrapper = $this->state->project->getWrapper();
    $form = parent::buildForm($form, $form_state);

    // Hide some fields depending upon investment type.
    switch ($this->state->project->getInvestmentType()) {
      case 'nachrangdarlehen':
        unset($form['field_inv_genussrecht']);
        break;
      case 'genussrecht':
        unset($form['field_inv_nachrangdarlehen']);
        break;
      case 'reward':
        unset($form['field_inv_genussrecht']);
        unset($form['field_inv_nachrangdarlehen']);
        break;
    }

    // After build callback to format number to float.
    $form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#after_build'] = array('software_selection_number_field_inv_investition_after_build');
    // Re-build form on amount change to validate it immediately.
    $form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#ajax'] = $this->defaultAjaxProperties();
    // Add custom amount validation.
    $form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#tmt_integer_range'] = array(
      'min' => $project_wrapper->field_invest_range_min->value(),
      'max' => $project_wrapper->field_invest_range_max->value(),
    );
    if (empty($form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#default_value'])) {
      $form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#default_value'] = $project_wrapper->field_invest_default_value->value();
    }

    // Hide pieces reference field from users.
    $form['field_inv_pieces_reference'][LANGUAGE_NONE][0]['target_id'] = array(
      '#type' => 'value',
    );

    if ($this->state->project->usesPiecePrices()) {
      unset($form['field_inv_investition']);
      $form_state['invest_by_piece'] = TRUE;
      $form = $this->buildPerPieceForm($form, $form_state);
      unset($form['field_inv_agreements']);
    }
    else {
      unset($form['field_inv_pieces_reference'][LANGUAGE_NONE][0]['target_id']['#value']);
      $form_state['invest_by_piece'] = FALSE;
      $this->buildInvestAsForm($form, $form_state);
    }

    // Add node project teaser.
    $form['project'] = node_view($this->state->project->node, 'teaser');
    $form['download'] = $this->renderFileDownloadButtons($form);

    return $form;
  }

  /**
   * Builds 'invest as' form.
   *
   * @param array $form
   *   The form for which to generate the section.
   * @param array $form_state
   *   The form state for which to generate the section.
   */
  protected function buildInvestAsForm(&$form, $form_state) {
    // Get invest as value with a fallback to user data.
    $invest_as = !empty($this->getUserInfo()->field_user_invest_as[LANGUAGE_NONE][0]['value']) ? $this->getUserInfo()->field_user_invest_as[LANGUAGE_NONE][0]['value'] : 'private';
    if (!empty($form_state['values']['field_user_invest_as'])) {
      $invest_as = $form_state['values']['field_user_invest_as'];
    }

    // Invest as radios.
    $form['field_user_invest_as'] = array(
      '#title' => t('I invest as'),
      '#type' => 'radios',
      '#options' => array(
        'private' => t('Private person'),
        'company' => t('Company'),
      ),
      '#default_value' => $invest_as,
      '#ajax' => $this->defaultAjaxProperties(),
    );
    if ($invest_as == 'private') {
      // Show agreements for private persons.
      $this->buildUserAgreementsForm($form, $form_state);
    }
    else {
      // Show company address for companies.
      $form['field_user_company_address'] = $this->buildCompanyAddressForm();
      // Remove agreements for private persons.
      unset($form['field_inv_agreements']);
    }
  }

  /**
   * Builds user agreements form.
   *
   * @param array $form
   *   The form for which to generate the agreements.
   * @param array $form_state
   *   The form state for which to generate the agreements.
   */
  function buildUserAgreementsForm(&$form, $form_state) {
    global $user;
    $investment_current = $this->getCurrentInvestmentAmount($form, $form_state);
    // Get annual user investment including current investment value.
    $investment_annual = $this->state->project->getUserInvestmentsTotalAnnual($user->uid);
    // For each project every private investor is only allowed to invest no more
    // than €5000,- within 12 months, except for when the investor agrees to one
    // or both of two agreements, which he has to actively check.
    if (($investment_annual + $investment_current) > 5000) {
      // User agreements text.
      $investments = $this->state->project->getUserInvestmentsAnnual($user->uid);
      $form['previous_investments'] = array(
        '#items' => array(),
        '#theme' => 'item_list',
      );
      foreach ($investments as $while) {
        $investment = TmtInvestment::create($while);
        $form['previous_investments']['#items'][] = tmt_core_format_currency($investment->getAmount()) . ' ' . t('on', array(), array('context' => 'SoftwareSelectionStepInvestment')) . ' ' . date('d.m.Y', $while->created);
      }
      // Add current investment to the list.
      if ($investment_current) {
        $form['previous_investments']['#items'][] = tmt_core_format_currency($investment_current) . ' ' . t('on', array(), array('context' => 'SoftwareSelectionStepInvestment')) . ' ' . date('d.m.Y');
      }
    }
    else {
      unset($form['field_inv_agreements']);
    }
  }

  /**
   * Get current investment amount.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   *
   * @return int
   *   The current investment amount.
   */
  protected function getCurrentInvestmentAmount(array $form, array $form_state) {
    $investment_current = 0;
    if ($this->state->project->usesPiecePrices()) {
      $piece_number = 0;
      if (!empty($form_state['values']['piece_number'])) {
        $piece_number = $form_state['values']['piece_number'];
      }
      else if (!empty($form['investment']['piece_number']['#default_value'])) {
        $piece_number = $form['investment']['piece_number']['#default_value'];
      }
      list($collection_wrapper, ) = $this->state->project->calculatePiecesInfo();
      $piece_price = $collection_wrapper->field_invest_pieces_amount->value();
      $investment_current = $piece_number * $piece_price;
    }
    else {
      if (isset($form_state['values']['field_inv_investition'][LANGUAGE_NONE][0]['value'])) {
        $investment_current = $form_state['values']['field_inv_investition'][LANGUAGE_NONE][0]['value'];
      }
      else if (isset($this->getEntity()->field_inv_investition[LANGUAGE_NONE][0]['value'])) {
        $investment_current = $this->getEntity()->field_inv_investition[LANGUAGE_NONE][0]['value'];
      }
      else if (isset($form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#default_value'])) {
        $investment_current = $form['field_inv_investition'][LANGUAGE_NONE][0]['value']['#default_value'];
      }
    }

    return $investment_current;
  }

  /**
   * Builds the company address form pre-populated by user data.
   *
   * @return array
   *   Built form array.
   */
  protected function buildCompanyAddressForm() {
    // Pseudo form and form state.
    $form = $form_state = array();
    $entity = $this->getUserInfo();
    $form_state['input']  = array();
    $form_state['entity'] = $entity;
    $form_state['build_info']['form_id'] = 'software_selection_step_invest_step_investment';
    field_attach_form('field_collection_item', $entity, $form, $form_state);
    return $form['field_user_company_address'];
  }

  /**
   * Renders the file download buttons.
   *
   * @param array $form
   *   The form for which to generate the download buttons.
   *
   * @return array
   *   The render array.
   */
  protected function renderFileDownloadButtons(&$form) {
    $wrapper = $this->state->project->getWrapper();
    $fields = array(
      // Key is the file field name, value is investment form element.
      'field_businessplan'=> 'field_inv_businessplan',
      'field_participation'=> 'field_inv_genussrecht',
      'field_trustee_contract'=> 'field_inv_treuhand_verwaltung',
      'field_nachrangdarlehen'=> 'field_inv_nachrangdarlehen',
      'field_gesellschaftervertrag'=> 'field_inv_gesellschaftervertrag',
    );
    $render = array();

    foreach ($fields as $field => $form_element) {
      if ($file = $wrapper->$field->value()) {
        if ($field == 'field_businessplan') {
          $render[$field]['title'] = array(
            '#markup' => $this->state->project->getBusinessPlanTitle(),
          );
        }
        $render[$field]['description'] = array(
          '#prefix' => '<p>',
          '#suffix' => '</p>',
          '#markup' => $this->state->project->getAcknowledgementText(str_replace('field_', '', $field)),
        );
        $render[$field]['file'] = array(
          '#markup' => l('', file_create_url($file['uri']), array('attributes' => array(
            'class' => 'tmt-icon',
            'target' => '_blank',
            'title' => $wrapper->get($field)->description->value(),
          ))),
        );
      }
      else {
        // Hide the checkbox if there is no file to render.
        unset($form[$form_element]);
      }
    }

    return $render;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {
    parent::validateForm($form, $form_state);

    // For each project every private investor is only allowed to invest no more
    // than €5000,- within 12 months, except for when the investor agrees to one
    // or both of two agreements, which he has to actively check.
    if (!empty($form_state['values']['field_user_invest_as']) && $form_state['values']['field_user_invest_as'] == 'private') {
      if (empty($form_state['values']['field_inv_agreements'][LANGUAGE_NONE][0]['value'])) {
        global $user;
        $inv_amount = $this->getCurrentInvestmentAmount($form, $form_state);
        $investment_annual = $this->state->project->getUserInvestmentsTotalAnnual($user->uid) + $inv_amount;
        if ($investment_annual > 5000) {
          form_error($form['field_inv_agreements'], 'Sofern Sie in dieses Projekt insgesamt mehr als € 5.000,- investieren möchten, bestätigen Sie bitte mindestens eine der beiden Vermögensauskünfte.');
        }
      }
    }

    if ($form_state['invest_by_piece']) {
      list($collection_wrapper, $num_left) = $this->state->project->calculatePiecesInfo();
      if (!$collection_wrapper || $form_state['values']['piece_number'] > $num_left) {
        form_error($form['investment']['piece_number'], t('There are not so many pieces left, please change your selection.'));
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $pseudo_form_state = $form_state;
    // Remove fields like field_user_invest_as which do not belong to entity for
    // a clean entity from state.
    // We should use 'pseudo' form state to not change original values.
    foreach ($pseudo_form_state['values'] as $key => $value) {
      if (strpos($key, 'field_') !== FALSE && !in_array($key, $this->displayedFields)) {
        unset($pseudo_form_state['values'][$key]);
      }
    }
    parent::submitForm($form, $pseudo_form_state);

    if ($form_state['invest_by_piece']) {
      $form_state['entity']->field_inv_num_pieces[LANGUAGE_NONE][0]['value'] = $form_state['values']['piece_number'];
      $form_state['entity']->field_inv_piece_price[LANGUAGE_NONE][0]['value'] = $form_state['values']['piece_price'];
      $investment_amount = $form_state['values']['piece_price'] * $form_state['values']['piece_number'];
      $form_state['entity']->field_inv_investition[LANGUAGE_NONE][0]['value'] = $investment_amount;
    }

    // Be sure to update the entity with the change in form state. This is
    // needed for the udpate to work with old PHP versions (5.3.2).
    $this->state->software_selection = $form_state['entity'];

    // Update field collection with user info.
    $entity = $this->getUserInfo();
    if (!empty($form_state['values']['field_user_invest_as'])) {
      $entity->field_user_invest_as[LANGUAGE_NONE][0]['value'] = $form_state['values']['field_user_invest_as'];
    }
    $entity->field_user_company_address = $form_state['values']['field_user_company_address'];
    entity_save('field_collection_item', $entity);

    $this->updateInvestmentInfoDetails();
  }

  /**
   * Updates the investment copy of the data with latest changes.
   *
   * While the changes are directly saved to the user entity's field collection,
   * we keep a copy for later reference in the investment entity.
   */
  protected function updateInvestmentInfoDetails() {
    $investment = entity_metadata_wrapper('while', $this->state->software_selection);
    /* @var $entity FieldCollectionItemEntity */
    $entity = $investment->field_investment_user_info->value();
    if (!$entity) {
      $entity = entity_create('field_collection_item', array('field_name' => 'field_investment_user_info'));
      $entity->setHostEntity('while', $this->state->software_selection);
    }
    // Copy over all fields of this step.
    $source_collection = $this->getUserInfo();
    $entity->field_user_invest_as = $source_collection->field_user_invest_as;
    $entity->field_user_company_address = $source_collection->field_user_company_address;
    // Do not save field collection. It will be saved at the very last step of
    // investment form together with the investment entity.
  }

  /**
   * Gets user info field collection from investor.
   *
   * @return stdClass
   *   User info field collection.
   */
  protected function getUserInfo() {
    $account = entity_metadata_wrapper('user', $this->state->user);
    /* @var $entity FieldCollectionItemEntity */
    $entity = $account->field_investment_user_info->value();
    if (!$entity) {
      $entity = entity_create('field_collection_item', array('field_name' => 'field_investment_user_info'));
      $entity->setHostEntity('user', $this->state->user);
    }
    return $entity;
  }

  /**
   * Defines default #ajax properties.
   *
   * @return array
   *   Default #ajax properties
   */
  protected function defaultAjaxProperties() {
    return array(
      'callback' => 'software_selection_default_ajax',
      'wrapper' => 'invest-step-investment__content',
      'effect' => 'fade',
      'speed' => 'fast',
      'step_class' => get_called_class(),
      'progress' => array(
        'type' => 'throbber',
        'message' => '',
      ),
    );
  }

  /**
   * Builds the per piece investment form details.
   *
   * @return $form
   *   The updated $form.
   */
  protected function buildPerPieceForm(&$form, &$form_state) {
    // Get remaining items.
    list($collection_wrapper, $num_left) = $this->state->project->calculatePiecesInfo();


    if ($collection_wrapper) {
      // Store pieces field collection reference.
      $form['field_inv_pieces_reference'][LANGUAGE_NONE][0]['target_id']['#value'] = $collection_wrapper->getIdentifier();

      $form['investment'] = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('investment-by-pieces')),
      );

      // All good - still pieces to invest in remaining
      // Set Title for pieces if present.
      $project_wrapper = $this->state->project->getWrapper();
      if ($project_wrapper->field_invest_pieces_title->value()) {
        $form['investment']['title'] = array(
          '#markup' => '<h3>' . $project_wrapper->field_invest_pieces_title->value() . '</h3>',
        );
      }

      $form['investment']['piece_price'] = array(
        '#type' => 'value',
        '#value' => $collection_wrapper->field_invest_pieces_amount->value(),
      );

      $investment = TmtInvestment::create($this->state->software_selection);
      if (!empty($form_state['values']['piece_number'])) {
        $piece_number = $form_state['values']['piece_number'];
      }
      else if ($number = $investment->getPieceNumber()) {
        $piece_number = $number;
      }
      else {
        $piece_number = 1;
      }

      // Selection of number of pieces.
      $form['investment']['piece_number'] = array(
        '#type' => 'select',
        '#max' => $num_left,
        '#options' => drupal_map_assoc(range(1, min(100, $num_left))),
        '#required' => TRUE,
        '#ajax' => $this->defaultAjaxProperties(),
        '#default_value' => $piece_number,
        '#prefix' => '<div class="investment-by-pieces__select"><span class="investment-by-pieces__select__prefix">' . t('I order') . '</span>',
        '#suffix' => '<span class="investment-by-pieces__select__suffix">' . $collection_wrapper->field_invest_pieces_name->value() . '</span></div>',
      );

      // Display of additional costs.
      if ($collection_wrapper->field_invest_pieces_addition->value()) {
        $form['investment']['additional_costs'] = array(
          '#prefix' => '<div class="investment-by-pieces__additional-costs">',
          '#markup' => $collection_wrapper->field_invest_pieces_addition->value->value(array('sanitize' => TRUE)),
          '#suffix' => '</div>',
        );
      }

      $piece_price = $collection_wrapper->field_invest_pieces_amount->value();
      $total_sum_formatted = tmt_core_format_currency($piece_number * $piece_price);
      // Total sum element.
      $form['investment']['total_sum'] = array(
        '#markup' => '<p class="investment-by-pieces__total-sum">' . t('Total price') . ' ' . $total_sum_formatted . '</p>',
      );

      // Display of additional costs information.
      if ($collection_wrapper->field_invest_pieces_add_footer->value()) {
        $form['investment']['additional_costs_footer'] = array(
          '#prefix' => '<div class="investment-by-pieces__additional-costs-footer">',
          '#markup' => $collection_wrapper->field_invest_pieces_add_footer->value->value(array('sanitize' => TRUE)),
          '#suffix' => '</div>',
        );
      }
    }
    else {
      drupal_set_message(t('Investment not possible - there are no pieces left'), 'error');
    }

    return $form;
  }

}
