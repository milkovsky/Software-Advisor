<?php

/**
 * @file
 * Form step for the further information.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepUserInfoFormBase;

/**
 * More information form step.
 */
class SoftwareSelectionStepMore extends SoftwareSelectionStepUserInfoFormBase {

  /**
   * {@inheritdoc}
   */
  protected $save = TRUE;

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_user_birthday',
    'field_user_telefon',
  );

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Additional data');
  }

  /**
   * {@inheritdoc}
   */
  public function getStepId() {
    return 'invest-step-more';
  }

  /**
   * {@inheritdoc}
   */
  public function getSubmitNextLabel() {
    return t('Save and continue');
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);
    // Do not render configured groups.
    unset($form['#fieldgroups']);

    // Fix size of telefon field to match textfields else.
    $form['field_user_telefon'][LANGUAGE_NONE][0]['value']['#size'] = 30;
    return $form;
  }

}
