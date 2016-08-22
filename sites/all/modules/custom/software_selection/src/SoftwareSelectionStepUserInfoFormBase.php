<?php

/**
 * @file
 * Form step for the detail information (address and tax info).
 */

namespace Drupal\software_selection;

/**
 * Base class for using
 */
abstract class SoftwareSelectionStepUserInfoFormBase extends SoftwareSelectionStepEntityForm {

  /**
   * {@inheritdoc}
   */
  protected $save = TRUE;

  /**
   * {@inheritdoc}
   */
  protected $entityType = 'field_collection_item';

  /**
   * {@inheritdoc}
   */
  public function getEntity() {
    $account = entity_metadata_wrapper('user', $this->state->user);
    $entity = $account->field_investment_user_info->value();
    if (!$entity) {
      $entity = entity_create('field_collection_item', array('field_name' => 'field_investment_user_info'));
      $entity->setHostEntity('user', $this->state->user);
    }
    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    parent::submitForm($form, $form_state);
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
    $entity = $investment->field_investment_user_info->value();
    if (!$entity) {
      $entity = entity_create('field_collection_item', array('field_name' => 'field_investment_user_info'));
      $entity->setHostEntity('while', $this->state->software_selection);
    }
    // Copy over all fields of this step.
    $source_collection = $this->getEntity();
    foreach ($this->displayedFields as $field_name) {
      $entity->$field_name = $source_collection->$field_name;
    }
    // Do not save as investment will be saved later during the process.
  }
}
