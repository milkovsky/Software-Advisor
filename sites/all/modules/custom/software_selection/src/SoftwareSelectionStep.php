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
   * Adds the default button to the form.
   *
   * @param array $form
   *   The form where to add the elements.
   * @param array $form_state
   *   The form state.
   *
   * @return array
   *   The updated form.
   */
  protected function buildButtons($form, &$form_state) {
    $form['actions'] = array(
      '#type' => 'actions',
    );
    // Keep the step used for reference.
    $form['#step-id'] = $this->getStepId();

    $form['actions']['cancel'] = array(
      '#type' => 'submit',
      '#name' => 'cancel',
      '#value' => t('Cancel'),
    );

    // Detect index of current step to manage action buttons display.
    $steps = $this->controller->getStepDefinition();
    $keys = array_keys($steps);
    $step_index = array_search($this->getStepId(), $keys);

    // Hide back button on the first step.
    if ($step_index > 0) {
      $form['actions']['back'] = array(
        '#type' => 'submit',
        '#name' => 'back',
        '#value' => t('Back'),
      );
    }

    $form['actions']['next'] = array(
      '#type' => 'submit',
      '#name' => 'next',
      '#value' => t('Next'),
    );

    // Change "Next" button text on the last step.
    if ($step_index == count($steps) - 1) {
      $form['actions']['next']['#value'] = t('Finish');
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);

    $form['summary']['#markup'] = $this->getTitle();
    $form = $this->buildButtons($form, $form_state);
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm($form, &$form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm($form, &$form_state) {
    $a = 2;
    #parent::submitForm($form, $form_stat);
  }

}
