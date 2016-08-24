<?php

/**
 * @file
 * Defines main Invest form controller.
 */

namespace Drupal\software_advisor;

/**
 * Main class for controlling and rendering the selection form.
 *
 * The form assumes that login already happened in a subsequent steps. The login
 * and registration form is not part of this, as it is handled differently: You
 * are not allowed to go back to register and/or login again.
 */
class SoftwareAdvisorFormController {

  /**
   * The selection state.
   *
   * @var SoftwareAdvisorFormState
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
   * @var SoftwareAdvisorFormStepBase[]
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
   * @param SoftwareAdvisorFormStepBase $step
   *   The step to render.
   *
   * @return array
   */
  protected function renderStepForm(SoftwareAdvisorFormStepBase $step) {
    return drupal_get_form('software_advisor_step_form', $step);
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
        $form_state['redirect'] = 'software-advisor/start';
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
        if (!isset($keys[$step_index + 1])) {
          node_save($this->state->software_selection);
          $this->clearStateData();
          drupal_set_message(t('You have successfully finished software selection! You can find your results below.'));
          $form_state['redirect'] = 'node/' . $this->state->software_selection->nid;
        }
        else {
          $next_step = $keys[$step_index + 1];
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
    $steps = $_SESSION['software_advisor_business_processes'];
    $names = SoftwareAdvisorUtil::getBusinessProcessNames();
    $this->stepDefinition = array();
    foreach ($steps as $step) {
      if (isset($names[$step])) {
        $this->stepDefinition[$step] = array(
          'title' => $names[$step],
          'handler' => __NAMESPACE__ . '\SoftwareAdvisorFormStepBusinessProcess',
        );
      }
    }
    $this->stepDefinition['metadata'] = array(
      'title' => 'Final step',
      'handler' => __NAMESPACE__ . '\SoftwareAdvisorFormStepMetadata',
    );
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
    $this->state = ctools_object_cache_get('submission', 'software_advisor');

    if ($reset || !isset($this->state)) {
      $step = key($this->stepDefinition);
      $this->state = SoftwareAdvisorFormState::create($step);
    }
  }

  /**
   * Saves the current selection state for later usage.
   */
  public function saveStateData() {
    ctools_include('object-cache');
    ctools_object_cache_set('submission', 'software_advisor', $this->state);
  }

  /**
   * Clears any saved selection state data.
   */
  public function clearStateData() {
    ctools_include('object-cache');
    ctools_object_cache_clear('submission', 'software_advisor');
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
   * @return SoftwareAdvisorFormStepBase
   */
  protected function getStep($step) {
    if (!isset($this->steps[$step])) {
      $handler = $this->stepDefinition[$step]['handler'];
      $this->steps[$step] = new $handler($this->state, $this);
    }
    return $this->steps[$step];
  }

  /**
   * Returns the current active step object.
   *
   * @return SoftwareAdvisorFormStepBase
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
   * @return SoftwareAdvisorFormState
   *   The state.
   */
  public function getState() {
    return $this->state;
  }

}
