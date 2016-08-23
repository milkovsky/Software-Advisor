<?php

/**
 * @file
 * Defines an utility class for the selection form.
 */

namespace Drupal\software_selection;

/**
 * Helper class with static utility methods.
 */
class SoftwareSelectionUtil {

  /**
   * Gets names of business processes.
   */
  public static function getBusinessProcessNames() {
    $vocabularies = taxonomy_get_vocabularies();
    
    $names = array();
    foreach ($vocabularies as $vocabulary) {
      if ($vocabulary->machine_name == 'categories') {
        continue;
      }
      $names[$vocabulary->machine_name] = $vocabulary->name;
    }
    
    return $names;
  }

  /**
   * Converts text to a machine name.
   *
   * @param string $name
   *   Text.
   *
   * @return string
   *   Machine name.
   */
  public static function toMachineName($name) {
    return preg_replace('@[^a-z0-9-]+@','_', strtolower($name));
  }

}