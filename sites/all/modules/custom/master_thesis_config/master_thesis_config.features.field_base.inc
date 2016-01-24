<?php
/**
 * @file
 * master_thesis_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function master_thesis_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_bug_tracking'.
  $field_bases['field_bug_tracking'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_bug_tracking',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'functions_bug_tracking',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_business_process'.
  $field_bases['field_business_process'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_business_process',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'bug_tracking' => 'Bug tracking',
        'communication' => 'Communication',
        'continuous_integration' => 'Continuous integration',
        'documentation' => 'Documentation',
        'events_management' => 'Events management',
        'invoicing' => 'Invoicing',
        'knowledge_management' => 'Knowledge management',
        'project_management' => 'Project management',
        'reporting' => 'Reporting',
        'time_tracking' => 'Time tracking',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_communication'.
  $field_bases['field_communication'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_communication',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'functions_communication',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_continuous_integration'.
  $field_bases['field_continuous_integration'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_continuous_integration',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_continuous_integration',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_documentation'.
  $field_bases['field_documentation'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_documentation',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'functions_documentation',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_events_management'.
  $field_bases['field_events_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_events_management',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_events_management',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_image'.
  $field_bases['field_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_invoicing'.
  $field_bases['field_invoicing'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_invoicing',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_invoicing',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_knowledge_management'.
  $field_bases['field_knowledge_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_knowledge_management',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_knowledge_management',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_project_management'.
  $field_bases['field_project_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_management',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'functions_project_management',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_reporting'.
  $field_bases['field_reporting'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_reporting',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_reporting',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_s_bug_tracking'.
  $field_bases['field_s_bug_tracking'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_bug_tracking',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_communication'.
  $field_bases['field_s_communication'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_communication',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_continuous_integration'.
  $field_bases['field_s_continuous_integration'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_continuous_integration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_documentation'.
  $field_bases['field_s_documentation'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_documentation',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_events_management'.
  $field_bases['field_s_events_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_events_management',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_invoicing'.
  $field_bases['field_s_invoicing'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_invoicing',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_knowledge_management'.
  $field_bases['field_s_knowledge_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_knowledge_management',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_project_management'.
  $field_bases['field_s_project_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_project_management',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_reporting'.
  $field_bases['field_s_reporting'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_reporting',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_time_tracking'.
  $field_bases['field_s_time_tracking'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_time_tracking',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'tiny',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_time_tracking'.
  $field_bases['field_time_tracking'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_time_tracking',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'funcitons_time_tracking',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
