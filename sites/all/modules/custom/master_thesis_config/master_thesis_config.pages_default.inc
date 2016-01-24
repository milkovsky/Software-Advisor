<?php
/**
 * @file
 * master_thesis_config.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function master_thesis_config_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit__panel_context_e0daf0f1-a2e1-46de-8689-a7b58107300e';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'General',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '69e0d958-2373-473c-9ddb-4052c9470bf9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-81ab934d-9494-4c7e-bf57-44f311fc3870';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '81ab934d-9494-4c7e-bf57-44f311fc3870';
    $display->content['new-81ab934d-9494-4c7e-bf57-44f311fc3870'] = $pane;
    $display->panels['middle'][0] = 'new-81ab934d-9494-4c7e-bf57-44f311fc3870';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-81ab934d-9494-4c7e-bf57-44f311fc3870';
  $handler->conf['display'] = $display;
  $export['node_edit__panel_context_e0daf0f1-a2e1-46de-8689-a7b58107300e'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit__panel_context_ff9f5cbe-cc40-4a8f-85a0-ecef083802e4';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Application',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'application' => 'application',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fa6f88c6-1fd7-443b-a447-fc969887946c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d62581f1-7e67-4e8f-a17d-b5dfd8b25cf8';
    $pane->panel = 'bottom';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd62581f1-7e67-4e8f-a17d-b5dfd8b25cf8';
    $display->content['new-d62581f1-7e67-4e8f-a17d-b5dfd8b25cf8'] = $pane;
    $display->panels['bottom'][0] = 'new-d62581f1-7e67-4e8f-a17d-b5dfd8b25cf8';
    $pane = new stdClass();
    $pane->pid = 'new-7aff1aaf-4609-4ac3-b20c-6aa06f1c5705';
    $pane->panel = 'left';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_business_process';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7aff1aaf-4609-4ac3-b20c-6aa06f1c5705';
    $display->content['new-7aff1aaf-4609-4ac3-b20c-6aa06f1c5705'] = $pane;
    $display->panels['left'][0] = 'new-7aff1aaf-4609-4ac3-b20c-6aa06f1c5705';
    $pane = new stdClass();
    $pane->pid = 'new-4f437104-a709-4b02-a869-121214ebae54';
    $pane->panel = 'left';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4f437104-a709-4b02-a869-121214ebae54';
    $display->content['new-4f437104-a709-4b02-a869-121214ebae54'] = $pane;
    $display->panels['left'][1] = 'new-4f437104-a709-4b02-a869-121214ebae54';
    $pane = new stdClass();
    $pane->pid = 'new-6c0799f6-d0b9-4745-9854-5b2b74bcf272';
    $pane->panel = 'left';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6c0799f6-d0b9-4745-9854-5b2b74bcf272';
    $display->content['new-6c0799f6-d0b9-4745-9854-5b2b74bcf272'] = $pane;
    $display->panels['left'][2] = 'new-6c0799f6-d0b9-4745-9854-5b2b74bcf272';
    $pane = new stdClass();
    $pane->pid = 'new-b3b9b133-6a5f-4b30-a15d-c9ceeb3803b3';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_bug_tracking';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b3b9b133-6a5f-4b30-a15d-c9ceeb3803b3';
    $display->content['new-b3b9b133-6a5f-4b30-a15d-c9ceeb3803b3'] = $pane;
    $display->panels['right'][0] = 'new-b3b9b133-6a5f-4b30-a15d-c9ceeb3803b3';
    $pane = new stdClass();
    $pane->pid = 'new-414949a9-b5bf-4ac9-a2ec-6af75b8da604';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_communication';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '414949a9-b5bf-4ac9-a2ec-6af75b8da604';
    $display->content['new-414949a9-b5bf-4ac9-a2ec-6af75b8da604'] = $pane;
    $display->panels['right'][1] = 'new-414949a9-b5bf-4ac9-a2ec-6af75b8da604';
    $pane = new stdClass();
    $pane->pid = 'new-eb4ced60-abc1-4e9f-8d2d-f60f6542c2e8';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_continuous_integration';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'eb4ced60-abc1-4e9f-8d2d-f60f6542c2e8';
    $display->content['new-eb4ced60-abc1-4e9f-8d2d-f60f6542c2e8'] = $pane;
    $display->panels['right'][2] = 'new-eb4ced60-abc1-4e9f-8d2d-f60f6542c2e8';
    $pane = new stdClass();
    $pane->pid = 'new-4d86c456-32d9-46e6-8cc6-30dc69ba5b7b';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_documentation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4d86c456-32d9-46e6-8cc6-30dc69ba5b7b';
    $display->content['new-4d86c456-32d9-46e6-8cc6-30dc69ba5b7b'] = $pane;
    $display->panels['right'][3] = 'new-4d86c456-32d9-46e6-8cc6-30dc69ba5b7b';
    $pane = new stdClass();
    $pane->pid = 'new-4fd1866e-4e11-49c2-b5c7-60b3b06473a5';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_events_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4fd1866e-4e11-49c2-b5c7-60b3b06473a5';
    $display->content['new-4fd1866e-4e11-49c2-b5c7-60b3b06473a5'] = $pane;
    $display->panels['right'][4] = 'new-4fd1866e-4e11-49c2-b5c7-60b3b06473a5';
    $pane = new stdClass();
    $pane->pid = 'new-c4165b9d-3aa0-4695-a6e6-ab6d8ea9aa3a';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_invoicing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c4165b9d-3aa0-4695-a6e6-ab6d8ea9aa3a';
    $display->content['new-c4165b9d-3aa0-4695-a6e6-ab6d8ea9aa3a'] = $pane;
    $display->panels['right'][5] = 'new-c4165b9d-3aa0-4695-a6e6-ab6d8ea9aa3a';
    $pane = new stdClass();
    $pane->pid = 'new-99460081-7e56-4993-8ee8-74b9bad35c78';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_knowledge_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '99460081-7e56-4993-8ee8-74b9bad35c78';
    $display->content['new-99460081-7e56-4993-8ee8-74b9bad35c78'] = $pane;
    $display->panels['right'][6] = 'new-99460081-7e56-4993-8ee8-74b9bad35c78';
    $pane = new stdClass();
    $pane->pid = 'new-54bc16c9-3042-4819-96df-cb1db10a0fce';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_project_management';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '54bc16c9-3042-4819-96df-cb1db10a0fce';
    $display->content['new-54bc16c9-3042-4819-96df-cb1db10a0fce'] = $pane;
    $display->panels['right'][7] = 'new-54bc16c9-3042-4819-96df-cb1db10a0fce';
    $pane = new stdClass();
    $pane->pid = 'new-d4467a77-8216-418e-aca2-90cc411ecd2e';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_reporting';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'd4467a77-8216-418e-aca2-90cc411ecd2e';
    $display->content['new-d4467a77-8216-418e-aca2-90cc411ecd2e'] = $pane;
    $display->panels['right'][8] = 'new-d4467a77-8216-418e-aca2-90cc411ecd2e';
    $pane = new stdClass();
    $pane->pid = 'new-6d695b9b-52c4-4611-82fd-0b3697714ba5';
    $pane->panel = 'right';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_time_tracking';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '6d695b9b-52c4-4611-82fd-0b3697714ba5';
    $display->content['new-6d695b9b-52c4-4611-82fd-0b3697714ba5'] = $pane;
    $display->panels['right'][9] = 'new-6d695b9b-52c4-4611-82fd-0b3697714ba5';
    $pane = new stdClass();
    $pane->pid = 'new-2157267d-6361-4f65-a93b-9cb57c6653fa';
    $pane->panel = 'top';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2157267d-6361-4f65-a93b-9cb57c6653fa';
    $display->content['new-2157267d-6361-4f65-a93b-9cb57c6653fa'] = $pane;
    $display->panels['top'][0] = 'new-2157267d-6361-4f65-a93b-9cb57c6653fa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit__panel_context_ff9f5cbe-cc40-4a8f-85a0-ecef083802e4'] = $handler;

  return $export;
}
