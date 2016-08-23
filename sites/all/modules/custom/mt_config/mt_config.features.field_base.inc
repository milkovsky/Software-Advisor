<?php
/**
 * @file
 * mt_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mt_config_field_default_field_bases() {
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

  // Exported field_base: 'field_app_crm'.
  $field_bases['field_app_crm'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_crm',
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
          'vocabulary' => 'crm',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_email_clients'.
  $field_bases['field_app_email_clients'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_email_clients',
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
          'vocabulary' => 'email_clients',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_events_management'.
  $field_bases['field_app_events_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_events_management',
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
          'vocabulary' => 'events_management',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_invoicing'.
  $field_bases['field_app_invoicing'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_invoicing',
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
          'vocabulary' => 'invoicing',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_project_management'.
  $field_bases['field_app_project_management'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_project_management',
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
          'vocabulary' => 'project_management',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_social_collaboration'.
  $field_bases['field_app_social_collaboration'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_social_collaboration',
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
          'vocabulary' => 'social_collaboration',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_app_time_tracking'.
  $field_bases['field_app_time_tracking'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_app_time_tracking',
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
          'vocabulary' => 'time_tracking',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_category'.
  $field_bases['field_category'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_category',
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
          'vocabulary' => 'categories',
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

  // Exported field_base: 'field_s_crm'.
  $field_bases['field_s_crm'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_crm',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_email_clients'.
  $field_bases['field_s_email_clients'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_email_clients',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
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
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
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
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
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
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_s_social_collaboration'.
  $field_bases['field_s_social_collaboration'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_social_collaboration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'double_field',
    'settings' => array(
      'first' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
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
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
      'second' => array(
        'maxlength' => 10,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  return $field_bases;
}
