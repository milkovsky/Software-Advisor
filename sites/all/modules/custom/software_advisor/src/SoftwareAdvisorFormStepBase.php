<?php

/**
 * @file
 * Defines abstract form step base class.
 */

namespace Drupal\software_advisor;

/**
 * Base class for investment form steps.
 */
abstract class SoftwareAdvisorFormStepBase {

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
   * @var SoftwareAdvisorFormState
   */
  protected $state;

  /**
   * The controller.
   *
   * @var SoftwareAdvisorFormController
   */
  protected $controller;

  /**
   * Constructs the object.
   *
   * @param SoftwareAdvisorFormState $state
   *   The current investment state.
   * @param SoftwareAdvisorFormController $controller
   *   The investment form controller.
   */
  public function __construct(SoftwareAdvisorFormState $state, SoftwareAdvisorFormController $controller) {
    $this->state = $state;
    $this->controller = $controller;
    $this->stepId = $state->activeStep;
    $steps = $controller->getStepDefinition();
    $this->title = $steps[$this->stepId]['title'];
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
    drupal_set_title('Software selection: ' . $this->getTitle());
    $form['#attributes']['class'][] = 'selection-form';
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
      '#value' => t('Cancel selection process'),
      '#limit_validation_errors' => array() ,
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
        '#attributes' => array('class' => array('btn', 'btn-primary', 'btn-lg')),
        '#limit_validation_errors' => array(),
      );
    }

    $form['actions']['next'] = array(
      '#type' => 'submit',
      '#name' => 'next',
      '#value' => t('Next step'),
      '#attributes' => array('class' => array('btn', 'btn-success', 'btn-lg')),
    );

    // Change "Next" button text on the last step.
    if ($step_index == count($steps) - 1) {
      $form['actions']['next']['#value'] = t('Finish');
    }

    return $form;
  }

}
