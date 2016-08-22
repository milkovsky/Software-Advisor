<?php

/**
 * @file
 * Form step for the competence information of the user form.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepUserInfoFormBase;

/**
 * Competences step.
 */
class SoftwareSelectionStepCompetences extends SoftwareSelectionStepUserInfoFormBase {

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_user_company',
    'field_user_riskcapital',
    'field_user_corecompetence',
    'field_user_experienceyears',
    'field_user_cause',
  );

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Competences');
  }

  /**
   * {@inheritdoc}
   */
  public function getStepId() {
    return 'invest-step-competences';
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
    return $form;
  }

}
