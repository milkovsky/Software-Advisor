<?php

/**
 * @file
 * Form step class.
 */

namespace Drupal\software_selection;

/**
 * Investment form summary step.
 */
class SoftwareSelectionStepBusinessProcess extends SoftwareSelectionStepBase {

  /**
   * {@inheritdoc}
   */
  public function getEntity() {
    return $this->state->software_selection;
  }

  /**
   * Gets field name of the selection node.
   *
   * @return string
   *   Field name.
   */
  public function getFieldName() {
    return 'field_s_' . $this->getStepId();
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm($form, &$form_state) {
    $form = parent::buildForm($form, $form_state);
    $form['#tree'] = TRUE;
    $form['#attributes']['class'][] = 'selection-form';

    $values = $this->getEntityFunctions();

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
            '#default_value' => isset($values[$category_tid]) ? $values[$category_tid] : 0,
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
          '#default_value' => isset($values[$tid]) ? $values[$tid] : 0,
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
    if ($form_state['triggering_element']['#name'] == 'next') {
      $entity = $this->getEntity();
      $field = $this->getFieldName();
      $entity->{$field} = NULL;

      // Collect rate values.
      $values = array();
      foreach ($form_state['values'] as $category_id => $value) {
        if (!empty($value['header']['value']) && is_numeric($category_id)) {
          $has_values = FALSE;
          foreach ($value['body'] as $tid => $rate) {
            if (!empty($rate)) {
              $values[$tid] = $rate;
              $has_values = TRUE;
            }
          }
          if ($has_values) {
            $values[$category_id] = $value['header']['value'];
          }
        }
      }

      // Add selected rates to the entity.
      foreach ($values as $tid => $rate) {
        $entity->{$field}[LANGUAGE_NONE][] = array(
          'first' => (int) $tid,
          'second' => (int) $rate,
        );
      }
    }
  }

  /**
   * Gets functions of the current entity for current step.
   *
   * @return int[]
   *   Function term IDs.
   */
  protected function getEntityFunctions() {
    $entity = $this->getEntity();
    $field = $this->getFieldName();
    $values = array();
    if (!empty($entity->{$field}[LANGUAGE_NONE])) {
      foreach ($entity->{$field}[LANGUAGE_NONE] as $value) {
        $values[$value['first']] = $value['second'];
      }
    }
    return $values;
  }

}
