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

    $form['#attributes']['class'][] = 'selection-form';

    $entity = isset($form_state['entity']) ? $form_state['entity'] : $this->getEntity();
    $form_state['entity'] = $entity;

    #$form['summary']['#markup'] = $this->getTitle();
    drupal_set_title('Software selection: ' . $this->getTitle());

    $tree = SoftwareSelectionUtil::getFunctionsTree($this->getStepId());
    foreach ($tree as $category_tid => $functions) {
      $category = taxonomy_term_load($category_tid);
      $form[$category_tid] = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('selection-form--category panel panel-default')),
        'header' => array(
          '#type' => 'container',
          '#attributes' => array('class' => array('panel-heading')),
          'value' => array(
            '#type' => 'rangefield',
            '#title' => $category->name,
            '#step' => 1,
            '#min' => 0,
            '#max' => 5,
            '#default_value' => 0,
          ),
        ),
      );
      $form[$category_tid]['body'] = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('panel-body')),
      );
      foreach ($functions as $tid => $function) {
        $form[$category_tid]['body'][$tid] = array(
          '#type' => 'rangefield',
          '#title' => $function,
          '#step' => 1,
          '#min' => 0,
          '#max' => 5,
          '#default_value' => 0,
        );
      }
    }

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

    /*if ($this->save) {
      entity_save($this->entityType, $form_state['entity']);
    }*/
  }

}
