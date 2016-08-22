<?php

/**
 * @file Confirmation step for risk information.
 */

namespace Drupal\software_selection\Steps;

use Drupal\software_selection\SoftwareSelectionStepEntityForm;

/**
 * Investment form risk step.
 */
class SoftwareSelectionStepRisk extends SoftwareSelectionStepEntityForm {

  /**
   * {@inheritdoc}
   */
  protected $displayedFields = array(
    'field_inv_agb',
    'field_inv_widerruf',
    'field_inv_risiko',
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
  public function getStepId() {
    return 'invest-step-risiko';
  }

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return t('Disclaimer');
  }

  /**
   * {@inheritdoc}
   */
  public function getSubmitLabel() {
    return t('Submit');
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);

    $form['widerruf'] = array(
      '#weight' => -500,
      '#markup' => '<h5>' . t('Cancellation Terms') . '</h5><p class="widerruf-text initial initial--dropped">'.  $this->state->project->getCustomizeableText('field_project_widerrufsbelehrung') . '</p>',
    );
    $form['field_inv_agb'][LANGUAGE_NONE]['#title'] = $this->state->project->getCustomizeableText('field_project_agb');
    $form['field_inv_widerruf'][LANGUAGE_NONE]['#title'] = t('I declare that I have read and understood the terms of cancellation and recognise that they form an integral part of this contract.');

    $form['risk_info'] = array(
      '#weight' => 60,
      '#markup' => '<h5>' . t('Risk Warning') . '</h5><p class="risk-text initial initial--dropped">'.  $this->state->project->getCustomizeableText('field_project_risks') . '</p>',
    );
    $form['field_inv_risiko']['#weight'] = 61;

    return $form;
  }

}
