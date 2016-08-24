<?php
/**
 * @file
 * software_advisor_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function software_advisor_config_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_functions|node|application|form';
  $field_group->group_name = 'group_functions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supported functions',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_management',
      1 => 'field_communication',
      2 => 'field_bug_tracking',
      3 => 'field_documentation',
      4 => 'field_events_management',
      5 => 'field_continuous_integration',
      6 => 'field_knowledge_management',
      7 => 'field_invoicing',
      8 => 'field_reporting',
      9 => 'field_time_tracking',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Supported functions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-functions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_functions|node|application|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Supported functions');

  return $field_groups;
}
