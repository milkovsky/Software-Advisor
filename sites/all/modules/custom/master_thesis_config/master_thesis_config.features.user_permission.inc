<?php
/**
 * @file
 * master_thesis_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function master_thesis_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator default_environment'.
  $permissions['access environment indicator default_environment'] = array(
    'name' => 'access environment indicator default_environment',
    'roles' => array(),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator local'.
  $permissions['access environment indicator local'] = array(
    'name' => 'access environment indicator local',
    'roles' => array(),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'create application content'.
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create software_selection content'.
  $permissions['create software_selection content'] = array(
    'name' => 'create software_selection content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any application content'.
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any software_selection content'.
  $permissions['delete any software_selection content'] = array(
    'name' => 'delete any software_selection content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own application content'.
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own software_selection content'.
  $permissions['delete own software_selection content'] = array(
    'name' => 'delete own software_selection content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in funcitons_continuous_integration'.
  $permissions['delete terms in funcitons_continuous_integration'] = array(
    'name' => 'delete terms in funcitons_continuous_integration',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in funcitons_events_management'.
  $permissions['delete terms in funcitons_events_management'] = array(
    'name' => 'delete terms in funcitons_events_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in funcitons_invoicing'.
  $permissions['delete terms in funcitons_invoicing'] = array(
    'name' => 'delete terms in funcitons_invoicing',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in funcitons_knowledge_management'.
  $permissions['delete terms in funcitons_knowledge_management'] = array(
    'name' => 'delete terms in funcitons_knowledge_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in funcitons_reporting'.
  $permissions['delete terms in funcitons_reporting'] = array(
    'name' => 'delete terms in funcitons_reporting',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in funcitons_time_tracking'.
  $permissions['delete terms in funcitons_time_tracking'] = array(
    'name' => 'delete terms in funcitons_time_tracking',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in functions_bug_tracking'.
  $permissions['delete terms in functions_bug_tracking'] = array(
    'name' => 'delete terms in functions_bug_tracking',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in functions_communication'.
  $permissions['delete terms in functions_communication'] = array(
    'name' => 'delete terms in functions_communication',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in functions_documentation'.
  $permissions['delete terms in functions_documentation'] = array(
    'name' => 'delete terms in functions_documentation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in functions_project_management'.
  $permissions['delete terms in functions_project_management'] = array(
    'name' => 'delete terms in functions_project_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any application content'.
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any software_selection content'.
  $permissions['edit any software_selection content'] = array(
    'name' => 'edit any software_selection content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own application content'.
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own software_selection content'.
  $permissions['edit own software_selection content'] = array(
    'name' => 'edit own software_selection content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in funcitons_continuous_integration'.
  $permissions['edit terms in funcitons_continuous_integration'] = array(
    'name' => 'edit terms in funcitons_continuous_integration',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in funcitons_events_management'.
  $permissions['edit terms in funcitons_events_management'] = array(
    'name' => 'edit terms in funcitons_events_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in funcitons_invoicing'.
  $permissions['edit terms in funcitons_invoicing'] = array(
    'name' => 'edit terms in funcitons_invoicing',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in funcitons_knowledge_management'.
  $permissions['edit terms in funcitons_knowledge_management'] = array(
    'name' => 'edit terms in funcitons_knowledge_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in funcitons_reporting'.
  $permissions['edit terms in funcitons_reporting'] = array(
    'name' => 'edit terms in funcitons_reporting',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in funcitons_time_tracking'.
  $permissions['edit terms in funcitons_time_tracking'] = array(
    'name' => 'edit terms in funcitons_time_tracking',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in functions_bug_tracking'.
  $permissions['edit terms in functions_bug_tracking'] = array(
    'name' => 'edit terms in functions_bug_tracking',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in functions_communication'.
  $permissions['edit terms in functions_communication'] = array(
    'name' => 'edit terms in functions_communication',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in functions_documentation'.
  $permissions['edit terms in functions_documentation'] = array(
    'name' => 'edit terms in functions_documentation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in functions_project_management'.
  $permissions['edit terms in functions_project_management'] = array(
    'name' => 'edit terms in functions_project_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'execute unlink files'.
  $permissions['execute unlink files'] = array(
    'name' => 'execute unlink files',
    'roles' => array(),
    'module' => 'ftools',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
