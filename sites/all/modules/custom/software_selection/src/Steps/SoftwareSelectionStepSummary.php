<?php

/**
 * @file
 * Form step class.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepEntityForm;

/**
 * Investment form summary step.
 */
class SoftwareSelectionStepSummary extends SoftwareSelectionStepEntityForm {

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_inv_anonym',
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
    return t('Summary');
  }

  /**
   * {@inheritdoc}
   */
  public function getStepId() {
    return 'invest-step-summary';
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
  protected function getDisplayedFields() {
    $project = TmtInvestment::create($this->getEntity())->getProject();
    $displayedFields = parent::getDisplayedFields();

    if ($project->getAllowNoGoodies() == TRUE) {
      $displayedFields[] = 'field_inv_no_goodies';
    }

    return $displayedFields;
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);
    // Add rendered summary of investment.
    $form['investment_summary'] = entity_view('while', array($this->getEntity()), 'summary');
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    parent::submitForm($form, $form_state);
    // Be sure to update the entity with the change in form state. This is
    // needed for the udpate to work with old PHP versions (5.3.2).
    $this->state->software_selection = $form_state['entity'];
  }
}

