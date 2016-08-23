<?php

/**
 * @file
 * Defines abstract form step base class.
 */

namespace Drupal\software_selection;

/**
 * Class for handling entity forms as form step.
 */
abstract class SoftwareSelectionStepEntityForm extends SoftwareSelectionStepBase {

  /**
   * The fields being displayed. Should be adapted.
   *
   * @var array
   */
  protected $displayedFields = array('field_s_email_clients');

  /**
   * The entity type id.
   *
   * @var string
   */
  protected $entityType = 'node';

  /**
   * Whether to save during submission.
   *
   * @var bool
   */
  protected $save = FALSE;

  /**
   * Gets the entity that should be edited.
   *
   * @return stdClass
   */
  abstract protected function getEntity();

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = $this->addDefaultForm($form, $form_state);

    $entity = isset($form_state['entity']) ? $form_state['entity'] : $this->getEntity();
    $form_state['entity'] = $entity;
    field_attach_form($this->entityType, $entity, $form, $form_state);

    list($id, $vid, $bundle) = entity_extract_ids($this->entityType, $entity);

    // Hide fields not being displayed.
    foreach (element_children($form) as $key) {
      if (!in_array($key, $this->getDisplayedFields())) {
        // Really remove the form elements, as making them inaccessible still
        // triggers form validated of some child elements via #element_validate.
        unset($form[$key]);
      }
    }
    // Hide metatags.
    unset($form['#metatags']);

    // Make sure the bundle is set during validation on the pseudo entity.
    $info = entity_get_info($this->entityType);
    $key = $info['entity keys']['bundle'];
    if ($key) {
      $form[$key] = array(
        '#type' => 'value',
        '#value' => $bundle
      );
    }

    $form = $this->buildButtons($form, $form_state);
    return $form;
  }

  /**
   * Gets the fields to display.
   *
   * @return array
   *   Returns an array with the keys of the fields to display.
   */
  protected function getDisplayedFields() {
    return $this->displayedFields;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {
    // Create a pseudo entity and validate - as done else.
    $pseudo_entity = (object) $form_state['values'];
    field_attach_form_validate($this->entityType, $pseudo_entity, $form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    entity_form_submit_build_entity($this->entityType, $form_state['entity'], $form, $form_state);
    if ($this->save) {
      entity_save($this->entityType, $form_state['entity']);
    }
  }

}
