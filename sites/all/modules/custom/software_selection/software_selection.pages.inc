<?php

/**
 * @file
 * Outputs the pages for the software selection workflow.
 */

use Drupal\software_selection\SoftwareSelectionController;
use Drupal\software_selection\SoftwareSelectionUtil;

/**
 * Page callback for selection page.
 */
function software_selection_start_form($form, &$form_state) {
  ctools_include('object-cache');
  $state = ctools_object_cache_get('submission', 'software_selection');
  if ($state) {
    // Redirect to the selection form is it is already in progress.
    drupal_goto('software-selection');
  }

  $form['info'] = array(
    '#type' => 'item',
    // @todo Add intro text with intro and instructions about the selection.
    '#markup' => t('Welcome to software selection process.'),
  );

  $names = SoftwareSelectionUtil::getBusinessProcessNames();
  $form['business_processes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose business processes you would like to manage:'),
    '#options' => $names,
    '#required' => TRUE,
  );
  // Populate values is they were already selected before.
  if (isset($_SESSION['software_selection_business_processes'])) {
    $form['business_processes']['#default_value'] = $_SESSION['software_selection_business_processes'];
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start software selection'),
  );
  return $form;
}

/**
 * Submit callback for selection page.
 */
function software_selection_start_form_submit($form, &$form_state) {
  $_SESSION['software_selection_business_processes'] = $form_state['values']['business_processes'];
  drupal_goto('software-selection');
}

/**
 * Page callback for selection page.
 */
function software_selection_page() {
  $render = SoftwareSelectionController::create()
    ->renderForm();

  $content = drupal_render($render);

  return $content;
}
