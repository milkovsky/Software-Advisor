<?php
/**
 * @file
 * software_advisor_config.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function software_advisor_config_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_my-selections:software-advisor/my.
  $menu_links['user-menu_my-selections:software-advisor/my'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'software-advisor/my',
    'router_path' => 'software-advisor/my',
    'link_title' => 'My selections',
    'options' => array(
      'identifier' => 'user-menu_my-selections:software-advisor/my',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_start-selection:software-advisor/start.
  $menu_links['user-menu_start-selection:software-advisor/start'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'software-advisor/start',
    'router_path' => 'software-advisor/start',
    'link_title' => 'Start selection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_start-selection:software-advisor/start',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Log out');
  t('My selections');
  t('Start selection');
  t('User account');

  return $menu_links;
}
