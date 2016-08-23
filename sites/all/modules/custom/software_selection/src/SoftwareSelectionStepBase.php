<?php

/**
 * @file
 * Defines abstract form step base class.
 */

namespace Drupal\software_selection;

/**
 * Base class for investment form steps.
 */
abstract class SoftwareSelectionStepBase {

  /**
   * Step title.
   *
   * @var string
   */
  protected $title;

  /**
   * Step id (machine name).
   *
   * @var string
   */
  protected $stepId;

  /**
   * The investment state.
   *
   * @var SoftwareSelectionState
   */
  protected $state;

  /**
   * The controller.
   *
   * @var SoftwareSelectionController
   */
  protected $controller;

  /**
   * Constructs the object.
   *
   * @param SoftwareSelectionState $state
   *   The current investment state.
   * @param SoftwareSelectionController $controller
   *   The investment form controller.
   */
  public function __construct(SoftwareSelectionState $state, SoftwareSelectionController $controller) {
    $this->state = $state;
    $this->controller = $controller;
    $this->stepId = $state->activeStep;
    $steps = $controller->getStepDefinition();
    $this->title = $steps[$this->stepId];
  }

  /**
   * Gets title for the construction of the form step.
   *
   * @return string
   *   The title.
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * Gets a human and machine readable step id, as suitable for HTML.
   *
   * @return string
   *   The id.
   */
  public function getStepId() {
    return $this->stepId;
  }

  /**
   * Gets the form elements for the step.
   *
   * For the validation and submit handlers to run, the investment form
   * controller must be written to $form_state['controller'].
   *
   * @param array $form
   *   The form where to add the elements.
   * @param array $form_state
   *   The form state.
   *
   * @return array
   *   The modified form.
   */
  public function buildForm($form, &$form_state) {
    $this->populateFormState($form, $form_state);
    return $form;
  }

  /**
   * Runs form validation and sets form errors as necessary.
   *
   * @param array $form
   *   The form where to add the elements.
   * @param array $form_state
   *   The form state.
   */
  abstract public function validateForm($form, &$form_state);

  /**
   * Runs the form submission handler of the step.
   *
   * @param array $form
   *   The form where to add the elements.
   * @param array $form_state
   *   The form state.
   */
  abstract public function submitForm($form, &$form_state);

  /**
   * Populates form state the selection form controller.
   *
   * @param array $form
   *   The form where to add the elements.
   * @param array $form_state
   *   The form state.
   */
  protected function populateFormState($form, &$form_state) {
    $form_state['controller'] = $this->controller;
  }

}
