<?php
/**
 * @file
 * master_thesis_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function master_thesis_config_taxonomy_default_vocabularies() {
  return array(
    'funcitons_continuous_integration' => array(
      'name' => 'Continuous integration funcitons',
      'machine_name' => 'funcitons_continuous_integration',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'funcitons_events_management' => array(
      'name' => 'Events management funcitons',
      'machine_name' => 'funcitons_events_management',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'funcitons_invoicing' => array(
      'name' => 'Invoicing funcitons',
      'machine_name' => 'funcitons_invoicing',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'funcitons_knowledge_management' => array(
      'name' => 'Knowledge management funcitons',
      'machine_name' => 'funcitons_knowledge_management',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'funcitons_reporting' => array(
      'name' => 'Reporting funcitons',
      'machine_name' => 'funcitons_reporting',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'funcitons_time_tracking' => array(
      'name' => 'Time tracking funcitons',
      'machine_name' => 'funcitons_time_tracking',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'functions_bug_tracking' => array(
      'name' => 'Bug tracking functions',
      'machine_name' => 'functions_bug_tracking',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'functions_communication' => array(
      'name' => 'Communication functions',
      'machine_name' => 'functions_communication',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'functions_documentation' => array(
      'name' => 'Documentation functions',
      'machine_name' => 'functions_documentation',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'functions_project_management' => array(
      'name' => 'Project management functions',
      'machine_name' => 'functions_project_management',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
