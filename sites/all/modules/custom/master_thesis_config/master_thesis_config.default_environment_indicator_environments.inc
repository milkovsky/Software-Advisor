<?php
/**
 * @file
 * master_thesis_config.default_environment_indicator_environments.inc
 */

/**
 * Implements hook_default_environment_indicator_environment().
 */
function master_thesis_config_default_environment_indicator_environment() {
  $export = array();

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'local';
  $environment->name = 'LOCAL';
  $environment->regexurl = '\\.local';
  $environment->settings = array(
    'color' => '#3d7b43',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['local'] = $environment;

  return $export;
}
