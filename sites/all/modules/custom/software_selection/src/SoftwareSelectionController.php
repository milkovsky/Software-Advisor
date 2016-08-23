<?php

/**
 * @file
 * Defines main Invest form controller.
 */

namespace Drupal\software_selection;

/**
 * Main class for controlling and rendering the selection form.
 *
 * The form assumes that login already happened in a subsequent steps. The login
 * and registration form is not part of this, as it is handled differently: You
 * are not allowed to go back to register and/or login again.
 */
class SoftwareSelectionController {

  /**
   * The selection state.
   *
   * @var SoftwareSelectionState
   */
  protected $state;

  /**
   * Array of form steps to use.
   *
   * @var string[]
   */
  protected $stepDefinition = array();

  /**
   * Static cache of initialized selection state objects.
   *
   * @var SoftwareSelectionStepBase[]
   */
  protected $steps;

  /**
   * Constructs the object.
   *
   * @return static
   */
  public static function create() {
    return new static();
  }

  /**
   * Constructs the object.
   */
  protected function __construct() {
    $this->initSteps();
    $this->initState();
  }

  /**
   * Gets and processes form of the current step.
   *
   * @return array
   *   The render array.
   */
  public function renderForm() {
    return $this->renderStepForm($this->getActiveStep());
  }

  /**
   * Renders a single step form.
   *
   * @param SoftwareSelectionStepBase $step
   *   The step to render.
   *
   * @return array
   */
  protected function renderStepForm(SoftwareSelectionStepBase $step) {
    return drupal_get_form('software_selection_step_form', $step);
  }

  /**
   * Validates the active form step.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   */
  public function validateForm($form, &$form_state) {
    $this->getActiveStep()->validateForm($form, $form_state);
  }

  /**
   * Submits all the active form step.
   *
   * This should be only invoked if there are no form errors.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   */
  public function submitForm($form, &$form_state) {
    $this->getActiveStep()->submitForm($form, $form_state);

    // After successful submission move on to next step.
    $keys = array_keys($this->stepDefinition);
    $step_index = array_search($this->state->activeStep, $keys);

    switch ($form_state['triggering_element']['#name']) {
      case 'cancel':
        // Clear saved data, move to start.
        $this->clearStateData();
        $form_state['redirect'] = 'software-selection/start';
        break;

      case 'back':
        // Move to the previous step.
        $previous_step = $keys[$step_index - 1];
        if (isset($this->stepDefinition[$previous_step])) {
          $this->state->activeStep = $previous_step;
        }
        $this->saveStateData();
        break;

      default:
        // Move to the next step.
        $next_step = $keys[$step_index + 1];
        if (!isset($this->stepDefinition[$next_step])) {
          $form_state['redirect'] = 'software-selection/success';
        }
        else {
          $this->state->activeStep = $next_step;
        }
        $this->saveStateData();
        break;
    }
  }

  /**
   * Initializes form steps.
   */
  protected function initSteps() {
    $steps = $_SESSION['software_selection_business_processes'];
    $names = SoftwareSelectionUtil::getBusinessProcessNames();
    $this->stepDefinition = array();
    foreach ($steps as $step) {
      if (isset($names[$step])) {
        $this->stepDefinition[$step] = $names[$step];
      }
    }
  }

  /**
   * Initializes the form state.
   *
   * It fetches the state from cache or creates a new one if necessary.
   *
   * @param boolean $reset
   *   (optional) True to reset state.
   */
  protected function initState($reset = FALSE) {
    // Load state from cache if existing.
    ctools_include('object-cache');
    $this->state = ctools_object_cache_get('submission', 'software_selection');

    if ($reset || !isset($this->state)) {
      $step = key($this->stepDefinition);
      $this->state = SoftwareSelectionState::create($step);
    }
  }

  /**
   * Saves the current selection state for later usage.
   */
  public function saveStateData() {
    ctools_include('object-cache');
    ctools_object_cache_set('submission', 'software_selection', $this->state);
  }

  /**
   * Clears any saved selection state data.
   */
  public function clearStateData() {
    ctools_include('object-cache');
    ctools_object_cache_clear('submission', 'software_selection');
  }

  /**
   * Getter for step definition.
   *
   * @return string[]
   *   Step definition.
   */
  public function getStepDefinition() {
    return $this->stepDefinition;
  }

  /**
   * Gets a step object for a given step class.
   *
   * @param string $step
   *   The step class for which the get the object for.
   *
   * @return SoftwareSelectionStepBase
   */
  protected function getStep($step) {
    if (!isset($this->steps[$step])) {
      $this->steps[$step] = new SoftwareSelectionStep($this->state, $this);
    }
    return $this->steps[$step];
  }

  /**
   * @deprecated
   *
   * Gets currently shown steps (all steps up to the currently active step).
   *
   * @return SoftwareSelectionStepBase[]
   *   An ordered array of step objects, keyed by step id.
   */
  public function getCurrentStep() {
    $active_step = $this->state->activeStep;

    $steps = array();
    foreach ($this->stepDefinition as $step_class) {
      $step = $this->getStep($step_class);
      $steps[$step->getStepId()] = $step;

      if ($step_class == $active_step) {
        break;
      }
    }

    return $steps;
  }

  /**
   * @deprecated
   *
   * Gets non-current steps, i.e. steps becoming active later.
   *
   * @return SoftwareSelectionStepBase[]
   *   An ordered array of step objects, keyed by step id.
   */
  public function getLaterSteps() {
    $active_step = $this->state->activeStep;

    $steps_are_later = FALSE;
    $steps = array();
    foreach ($this->stepDefinition as $step_class) {
      if ($steps_are_later) {
        $step = $this->getStep($step_class);
        $steps[$step->getStepId()] = $step;
      }
      if ($step_class == $active_step) {
        $steps_are_later = TRUE;
      }
    }
    return $steps;
  }

  /**
   * Returns the current active step object.
   *
   * @return SoftwareSelectionStepBase
   *   The step object.
   */
  public function getActiveStep() {
    return $this->getStep($this->state->activeStep);
  }

  /**
   * PHP Magic function to control serialization.
   */
  public function __sleep() {
    $vars = get_object_vars($this);
    // Do not serialize step objects.
    unset($vars['steps']);
    return array_keys($vars);
  }

  /**
   * Returns the selection state.
   *
   * @return SoftwareSelectionState
   *   The state.
   */
  public function getState() {
    return $this->state;
  }

}
