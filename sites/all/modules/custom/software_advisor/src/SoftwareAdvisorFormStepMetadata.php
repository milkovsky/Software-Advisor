<?php

/**
 * @file
 * Form step class.
 */

namespace Drupal\software_advisor;

/**
 * Investment form summary step.
 */
class SoftwareAdvisorFormStepMetadata extends SoftwareAdvisorFormStepBase {

  /**
   * Gets selection entity from step state.
   *
   * @return \stdClass
   *   Selection node.
   */
  public function getEntity() {
    return $this->state->software_selection;
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);

    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Enter name of your selection, you can find it later in your selections list.'),
    );

    $form['notes'] = array(
      '#type' => 'textarea',
      '#title' => t('Notes'),
      '#description' => t('Enter notes to describe your selection project.'),
    );

    $form = $this->buildButtons($form, $form_state);

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {
    if (empty($form_state['values']['title'])) {
      $limit_validation_errors = NULL;
      if ($form_state['triggering_element']['#limit_validation_errors'] !== FALSE) {
        $limit_validation_errors = $form_state['triggering_element']['#limit_validation_errors'];
      }
      form_set_error('title', t('Title field is required.'), $limit_validation_errors);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    if ($form_state['triggering_element']['#name'] == 'next') {
      $entity = $this->getEntity();
      $entity->title = $form_state['values']['title'];
      $entity->body[LANGUAGE_NONE][0]['value'] = $form_state['values']['notes'];
    }
  }

}
