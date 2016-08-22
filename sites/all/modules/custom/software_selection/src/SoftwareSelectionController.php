<?php

/**
 * @file
 * Defines main Invest form controller.
 */

namespace Drupal\software_selection;

/**
 * Main class for controlling and rendering the investment form.
 *
 * The form assumes that login already happened in a subsequent steps. The login
 * and registration form is not part of this, as it is handled differently: You
 * are not allowed to go back to register and/or login again.
 */
class SoftwareSelectionController {

  /**
   * The investment state.
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
   * Static cache of initialized investment state objects.
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
    $step_title = $step->getTitle();
    $step_form = drupal_get_form('software_selection_step_form', $step);

    return array(
      '#prefix' => '<section id="' . $step->getStepId() . '" class="invest-step">' . $step_title,
      '#suffix' => '</section>',
      'form' => $step_form,
    );
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
    if (!empty($form_state['triggering_element']['#step_class'])) {
      // Update the active step based upon the pressed element.
      $this->state->activeStep = $form_state['triggering_element']['#step_class'];
    }
    // Fallback for non-submit elements ajax calls. It is necessary because
    // '#step_class' is not working for 'radios' and 'textfield' ajax calls.
    else if (!empty($form_state['triggering_element']['#ajax']['step_class'])) {
      // Update the active step based upon the pressed element.
      $this->state->activeStep = $form_state['triggering_element']['#ajax']['step_class'];
    }
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
    $step_index = array_search($this->state->activeStep, $this->stepDefinition);

    if (!isset($this->stepDefinition[$step_index + 1])) {
      $form_state['redirect'] = 'invest/' . $this->state->project->node->nid . '/success';
    }
    else {
      $this->state->activeStep = $this->stepDefinition[$step_index + 1];
    }

    $this->saveStateData();
  }

  /**
   * Initializes form steps.
   */
  protected function initSteps() {
    $names = SoftwareSelectionUtil::getBusinessProcessNames();
    $this->stepDefinition = array();
    foreach ($names as $name) {
      $step_machine_name = SoftwareSelectionUtil::toMachineName($name);
      $this->stepDefinition[$step_machine_name] = $name;
    }
  }

  /**
   * Initializes the form state.
   *
   * It fetches the state from cache or creates a new one if necessary.
   */
  protected function initState() {
    // Load state from cache if existing.
    ctools_include('object-cache');
    $this->state = ctools_object_cache_get('submission', 'software_selection');

    if (!isset($this->state)) {
      $step = key($this->stepDefinition);
      $this->state = SoftwareSelectionState::create($step);
    }
  }

  /**
   * Saves the current investment state for later usage.
   */
  public function saveStateData() {
    ctools_include('object-cache');
    ctools_object_cache_set('submission', 'software_selection', $this->state);
  }

  /**
   * Clears any saved investment state data.
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
   * Returns the investment state.
   *
   * @return SoftwareSelectionState
   *   The state.
   */
  public function getState() {
    return $this->state;
  }

}
