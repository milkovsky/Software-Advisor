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

  protected $title;
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
   * Gets the label of the submit button.
   *
   * @return string
   *   The label.
   */
  abstract public function getSubmitLabel();

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
  abstract public function buildForm($form, &$form_state);

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
   * Populates form state the investment form controller.
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
   * Adds default form elements, such as ajaxifying it.
   *
   * @param array $form
   *   The root form array.
   * @param array $form_state
   *   The form state.
   *
   * @return array
   *   The updated form.
   */
  protected function addDefaultForm($form, &$form_state) {
    $this->populateFormState($form, $form_state);
    // The wrapper div used by #ajax is added by the controller's render Form
    // method already.
    $form['#prefix'] = '<div id="'. $this->getStepId() . '__content" class="invest-step__content">';
    $form['#suffix'] = '</div>';
    // Make sure the form submits to the right path even if it is loaded the
    // first time via ajax.
    $form['#action'] = url('invest/' . $this->state->project->node->nid);
    return $form;
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
  protected function addDefaultButton($form, &$form_state) {
    // Build default submit button.
    $form['actions'] = array(
      '#type' => 'actions',
    );
    // Keep the step used for reference.
    $form['#step-id'] = $this->getStepId();

    $form['actions']['submit-step'] = array(
      '#type' => 'submit',
      // We need to set a custom, unique ID here as Drupal fails to make them
      // unique during ajax requests else. This is, drupal resets html IDs seen
      // during form building if there are no violations fails. But that is
      // problematic when we render another form later on which tries to use the
      // same ID.
      '#id' => drupal_html_id('edit-button-submit-' . $this->getStepId()),
      '#name' => $this->getStepId(),
      '#value' => $this->getSubmitLabel(),
      '#step_class' => get_called_class(),
      '#validate' => array('software_selection_step_form_validate'),
      '#submit' => array('software_selection_step_form_submit'),
      '#ajax' => array(
        'callback' => 'software_selection_reload_form',
      ) + software_selection_default_ajax($form, $form_state, $form['#step-id'] . '__content')
    );

    return $form;
  }

  /**
   * Gets the ajax result for this step, when the submit button is pressed.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   *
   * @return array
   *   A render array as accepted by ajax_form_callback() or an array of form
   *   elements to render as result.
   */
  public function getAjaxCommands($form, &$form_state) {
    if (form_get_errors()) {
      // Just show the form again with the form errors.
      return $form;
    }
    else {
      // Refresh current form so e.g. marked validation errors go away.
      $commands[] = ajax_command_replace('#'. $form['#step-id'] . '__content', drupal_render($form));

      // Render the next form and show that.
      $render = $this->controller->renderForm();

      $commands[] = ajax_command_replace(
        '#'. $this->controller->getActiveStep()->getStepId(),
        drupal_render($render)
      );
      // Add the status messages inside the new content's wrapper element.
      $commands[] = ajax_command_prepend('#'. $this->controller->getActiveStep()->getStepId(), theme('status_messages'));
      // Hide later steps.
      foreach ($this->controller->getLaterSteps() as $step) {
        $commands[] = ajax_command_invoke('#'. $step->getStepId(), 'removeClass', array('invest-step--active'));
        $commands[] = ajax_command_invoke('#'. $step->getStepId(), 'addClass', array('invest-step--disabled'));
        $commands[] = ajax_command_replace('#'. $step->getStepId() . ' form', '');
      }
      // Make sure all behaviours are re-attached. Drupal by default only does
      // it for the form the issued the ajax request, but that is not enough.
      $commands[] = array(
        'command' => 'reAttachFormBehaviours',
        'data' => array(),
      );
      // Scroll to the last active step.
      $commands[] = array(
        'command' => 'tmtInvestmentFormScrollToLastStep',
        'data' => array(),
      );

      return array(
        '#type' => 'ajax',
        '#commands' => $commands
      ) + element_info('ajax');
    }
  }
}
