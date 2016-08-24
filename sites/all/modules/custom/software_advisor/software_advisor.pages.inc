<?php

/**
 * @file
 * Outputs the pages for the software selection workflow.
 */

use Drupal\software_advisor\SoftwareAdvisorFormController;
use Drupal\software_advisor\SoftwareAdvisorUtil;

/**
 * Page callback for selection page.
 */
function software_advisor_start_form($form, &$form_state) {
  ctools_include('object-cache');
  $state = ctools_object_cache_get('submission', 'software_advisor');
  if ($state) {
    // Redirect to the selection form is it is already in progress.
    drupal_goto('software-advisor');
  }

  $form['info'] = array(
    '#type' => 'item',
    // @todo Add intro text with intro and instructions about the selection.
    '#markup' => t('Welcome to software selection process.'),
  );

  $names = SoftwareAdvisorUtil::getBusinessProcessNames();
  $form['business_processes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose business processes you would like to manage:'),
    '#options' => $names,
    '#required' => TRUE,
  );
  // Populate values is they were already selected before.
  if (isset($_SESSION['software_advisor_business_processes'])) {
    $form['business_processes']['#default_value'] = $_SESSION['software_advisor_business_processes'];
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
function software_advisor_start_form_submit($form, &$form_state) {
  $_SESSION['software_advisor_business_processes'] = $form_state['values']['business_processes'];
  drupal_goto('software-advisor');
}

/**
 * Page callback for selection page.
 */
function software_advisor_page() {
  if (!isset($_SESSION['software_advisor_business_processes'])) {
    drupal_goto('software-advisor/start');
  }

  $render = SoftwareAdvisorFormController::create()
  ->renderForm();

  $content = drupal_render($render);

  return $content;
}
