<?php

/**
 * @file
 * Form step for the address info.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepUserInfoFormBase;

/**
 * Address information form step.
 */
class SoftwareSelectionStepAddress extends SoftwareSelectionStepUserInfoFormBase {

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_user_address',
    'field_user_address_inv_separated',
    'field_user_address_invoice',
  );

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Address');
  }

  /**
   * {@inheritdoc}
   */  public function getStepId() {
    return 'invest-step-address';
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
    $form = parent::buildForm($form, $form_state);
    // Do not render configured groups.
    unset($form['#fieldgroups']);

    // Set name default values.
    $account = $this->state->user;
    $wrapper = entity_metadata_wrapper('user', $account);
    if (empty($form['field_user_address'][LANGUAGE_NONE][0]['#address']['first_name'])) {
      $form['field_user_address'][LANGUAGE_NONE][0]['#address']['first_name'] = $wrapper->field_name->value();
      $form['field_user_address'][LANGUAGE_NONE][0]['#address']['last_name'] = $wrapper->field_last_name->value();
    }
    if (empty($form['field_user_address_invoice'][LANGUAGE_NONE][0]['#address']['first_name'])) {
      $form['field_user_address_invoice'][LANGUAGE_NONE][0]['#address']['first_name'] = $wrapper->field_name->value();
      $form['field_user_address_invoice'][LANGUAGE_NONE][0]['#address']['last_name'] = $wrapper->field_last_name->value();
    }

    // Only validate required fields of invoice address if enabled.
    $form['#conditional_required'] = array(
      'targets' => array(
        array('field_user_address_invoice'),
      ),
      'value_exists' => array('field_user_address_inv_separated', LANGUAGE_NONE)
    );
    $form['#after_build'] = array('druform_conditional_required_after_build');

    // Add a wrapper element around the address to put them left.
    $form['field_user_address']['#prefix'] = '<section class="field-group-user-address">';
    $form['field_user_address_inv_separated']['#suffix'] = '</section>';

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    // Workaround to fix addressfield empty value. It saves country always.
    if (empty($form_state['values']['field_user_address_inv_separated'][LANGUAGE_NONE][0]['value'])) {
      if (!empty($form_state['values']['field_user_address_invoice'][LANGUAGE_NONE])) {
        unset($form_state['values']['field_user_address_invoice'][LANGUAGE_NONE]);
      }
      if (!empty($form_state['entity']->field_user_address_invoice[LANGUAGE_NONE])) {
        unset($form_state['entity']->field_user_address_invoice[LANGUAGE_NONE]);
      }
    }
    parent::submitForm($form, $form_state);
  }

}
