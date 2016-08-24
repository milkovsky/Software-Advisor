<?php
/**
 * @file
 * software_advisor_config.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function software_advisor_config_conditional_fields_default_fields() {
  $items = array();

  $items["node:application:0"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_bug_tracking',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'bug_tracking' => 'bug_tracking',
        'project_management' => NULL,
        'communication' => NULL,
        'documentation' => NULL,
        'time_tracking' => NULL,
        'events_management' => NULL,
        'continuous_integration' => NULL,
        'knowledge_management' => NULL,
        'invoicing' => NULL,
        'reporting' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'bug_tracking',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:1"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_communication',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'communication' => 'communication',
        'project_management' => NULL,
        'bug_tracking' => NULL,
        'documentation' => NULL,
        'time_tracking' => NULL,
        'events_management' => NULL,
        'continuous_integration' => NULL,
        'knowledge_management' => NULL,
        'invoicing' => NULL,
        'reporting' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'communication',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:2"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_continuous_integration',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'continuous_integration' => 'continuous_integration',
        'project_management' => NULL,
        'communication' => NULL,
        'bug_tracking' => NULL,
        'documentation' => NULL,
        'time_tracking' => NULL,
        'events_management' => NULL,
        'knowledge_management' => NULL,
        'invoicing' => NULL,
        'reporting' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'continuous_integration',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:3"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_documentation',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'documentation' => 'documentation',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'events_management' => NULL,
        'invoicing' => NULL,
        'knowledge_management' => NULL,
        'project_management' => NULL,
        'reporting' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'documentation',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:4"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_events_management',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'events_management' => 'events_management',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'invoicing' => NULL,
        'knowledge_management' => NULL,
        'project_management' => NULL,
        'reporting' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'events_management',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:5"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_invoicing',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'invoicing' => 'invoicing',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'events_management' => NULL,
        'knowledge_management' => NULL,
        'project_management' => NULL,
        'reporting' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'invoicing',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:6"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_knowledge_management',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'knowledge_management' => 'knowledge_management',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'events_management' => NULL,
        'invoicing' => NULL,
        'project_management' => NULL,
        'reporting' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'knowledge_management',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:7"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_project_management',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'project_management' => 'project_management',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'events_management' => NULL,
        'invoicing' => NULL,
        'knowledge_management' => NULL,
        'reporting' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'project_management',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:8"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_reporting',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'reporting' => 'reporting',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'events_management' => NULL,
        'invoicing' => NULL,
        'knowledge_management' => NULL,
        'project_management' => NULL,
        'time_tracking' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'reporting',
        ),
      ),
      'values' => array(),
    ),
  );

  $items["node:application:9"] = array(
    'entity' => 'node',
    'bundle' => 'application',
    'dependent' => 'field_time_tracking',
    'dependee' => 'field_business_process',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => 1,
          2 => 2,
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => 1,
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => 1,
          3 => 0,
        ),
        2 => array(
          1 => 1,
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => 1,
      'value_form' => array(
        'time_tracking' => 'time_tracking',
        'bug_tracking' => NULL,
        'communication' => NULL,
        'continuous_integration' => NULL,
        'documentation' => NULL,
        'events_management' => NULL,
        'invoicing' => NULL,
        'knowledge_management' => NULL,
        'project_management' => NULL,
        'reporting' => NULL,
      ),
      'value' => array(
        0 => array(
          'value' => 'time_tracking',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
