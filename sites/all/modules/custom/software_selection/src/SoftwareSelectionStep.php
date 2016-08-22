<?php

/**
 * @file
 * Form step class.
 */

namespace Drupal\software_selection;

/**
 * Investment form summary step.
 */
class SoftwareSelectionStep extends SoftwareSelectionStepBase {

  /**
   * {@inheritdoc}
   */
  public function getEntity() {
    return $this->state->software_selection;
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
    // Add rendered summary of investment.
    $form['investment_summary']['#markup'] = 'XXX';
    $form = $this->addDefaultButton($form, $form_state);
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {
    #parent::validateForm($form, $form_stat);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    #parent::submitForm($form, $form_stat);
  }

}
