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

/**
 * Page callback for successful investments.
 *
 * @param $project_node
 *   The project node.
 *
 * @return array
 */
function software_selection_result_page($project_node) {
  // Only display this once and clear the state for future investments.
  $controller = SoftwareSelectionController::create();
  $state = $controller->getState();
  $controller->clearStateData();

  // Check the payment state. If there is no finished investment to show,
  // redirect to the investment form.
  $payment_state = isset($state->payment) ? $state->payment->getStatus()->status : FALSE;
  if (!
   (payment_status_is_or_has_ancestor($payment_state, WIRECARD_PAYMENT_STATUS_APPROVED) ||
    payment_status_is_or_has_ancestor($payment_state, PAYMENT_STATUS_PENDING) ||
    payment_status_is_or_has_ancestor($payment_state, PAYMENT_STATUS_SUCCESS)
  )) {
    drupal_goto('invest/' . $project_node->nid);
  }
  // Auto-open PDF.
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'Refresh',
      'content' => '5; URL=' . url('investment/' . $state->software_selection->id . '/pdf'),
    ),
  );
  drupal_add_html_head($element, 'download_refresh');

  drupal_set_title(t('Thank you for your investment'));

  // Get projects views pane.
  module_load_include('inc', 'views_content', 'plugins/content_types/views_panes');
  $subtype = 'section_projects-section_or_all_pane';
  $conf = array(
    'items_per_page' => 2,
    'offset' => 0,
    'more_link' => 1,
    'override_title' => 0,
    'override_title_heading' => '',
    'override_title_text' => '',
    'pager_id' => 0,
    'use_pager' => 0,
    'context' => array('section', 'project'),
  );
  $context = array(
    'section' => ctools_context_create('node', tmt_section_get_active_node()),
    'project' => ctools_context_create('node', $project_node),
  );
  $pane = views_content_views_panes_content_type_render($subtype, $conf, array(), $context);

  $render = array();
  if ($views_output = render($pane->content)) {
    $render['projects']['#markup'] = '<h4 class="text--brand">' . t('These projects could also be interesting for you') . '</h4>';
    $render['projects']['#markup'] .= $views_output;
  }

  return $render;
}

/**
 * Checks access for investment process result page.
 */
function software_selection_result_page_access($project_node) {
  global $user;

  $state = SoftwareSelectionController::create($project_node)
    ->getState();
  $investment = $state->software_selection;

  if ($investment->uid == $user->uid || entity_access('view', 'while', $investment)) {
    return TRUE;
  }
  return FALSE;
}
