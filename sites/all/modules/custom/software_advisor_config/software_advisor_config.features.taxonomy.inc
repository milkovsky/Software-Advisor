<?php
/**
 * @file
 * software_advisor_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function software_advisor_config_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categories',
      'machine_name' => 'categories',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'crm' => array(
      'name' => 'CRM functions',
      'machine_name' => 'crm',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'email_clients' => array(
      'name' => 'Email clients functions',
      'machine_name' => 'email_clients',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'events_management' => array(
      'name' => 'Events management functions',
      'machine_name' => 'events_management',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'invoicing' => array(
      'name' => 'Invoicing functions',
      'machine_name' => 'invoicing',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'project_management' => array(
      'name' => 'Project management functions',
      'machine_name' => 'project_management',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'social_collaboration' => array(
      'name' => 'Social collaboration functions',
      'machine_name' => 'social_collaboration',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'time_tracking' => array(
      'name' => 'Time tracking functions',
      'machine_name' => 'time_tracking',
      'description' => NULL,
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
