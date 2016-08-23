<?php

/**
 * @file
 * Pages file.
 */

/**
 * Import form.
 */
function mt_import_form($form, &$form_state) {
  $form['info'] = array(
    '#type' => 'item',
    '#markup' => t('Submit to import applications and functions from !file.', array(
      '!file' => drupal_get_path('module', 'mt_import') . '/import/import.xlsx',
    )),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );
  return $form;
}

/**
 * Import form submit callback.
 */
function mt_import_form_submit($form, &$form_state) {
  $results = mt_import_get_contents();

  // Set true to remove all the vocabularies first,
  $clear = FALSE;

  if ($clear) {
    $vocabularies = taxonomy_get_vocabularies();
    foreach ($vocabularies as $vocabulary) {
      taxonomy_vocabulary_delete($vocabulary->vid);
    }
  }

  $applications = array();

  foreach ($results as $title => $rows) {
    if ($clear) {
      $machine_name = mt_import_get_machine_name($title);
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($machine_name)) {
        taxonomy_vocabulary_delete($vocabulary->vid);
      }
    }

    $vocabulary = mt_import_taxonomy_vocabulary_load_or_create_by_title("$title functions");
    $categories_vocabulary = mt_import_taxonomy_vocabulary_load_or_create_by_title('Categories');

    mt_import_initialize_vocabulary_fields($vocabulary);

    $category = NULL;
    $result_applications = NULL;

    foreach ($rows as $row_number => $row) {
      // Get application names from the 1st row.
      if ($row_number == 1) {
        $row = array_filter($row, create_function('$value', 'return !empty($value);'));
        $result_applications = array_slice($row, 1);
        continue;
      }

      if (empty($row['A']) || $row['A'] == 'Total') {
        // Skip empty rows and the total row.
        continue;
      }
      if (!isset($row['B'])) {
        // Save category.
        $name = $row['A'];
        $category = mt_import_taxonomy_term_load_or_create_by_name($name, $categories_vocabulary);
      }
      else {
        // Add 'function' term and assign function's category.
        $name = $row['A'];
        $term = mt_import_taxonomy_term_load_or_create_by_name($name, $vocabulary);
        $term->field_category[LANGUAGE_NONE][0]['tid'] = (int) $category->tid;
        taxonomy_term_save($term);

        // Collect application values.
        foreach ($result_applications as $key => $application) {
          if (!empty($row[$key])) {
            $applications[$application][$title][$name] = $row[$key];
          }
        }
      }
    }
  }

  // Create/update applications.
  foreach ($applications as $application_name => $application_types) {
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'application')
      ->propertyCondition('title', $application_name)
      ->propertyCondition('status', 1)
      ->range(0,1)
      ->execute();
    if (!empty($entities['node'])) {
      $results = array_keys($entities['node']);
      $nid = array_shift($results);
      $node = node_load($nid);
    }
    else {
      $node = new \stdClass();
      $node->type = 'application';
      $node->status = 1;
      $node->title = $application_name;
    }

    // Set application functions.
    foreach ($application_types as $application_type => $functions) {
      $vocabulary = mt_import_taxonomy_vocabulary_load_or_create_by_title($application_type);
      $application_field = "field_app_{$vocabulary->machine_name}";
      $node->{$application_field} = NULL;

      foreach ($functions as $function => $value) {
        if ($value) {
          $term = mt_import_taxonomy_term_load_or_create_by_name($function, $vocabulary);
          $node->{$application_field}[LANGUAGE_NONE][]['tid'] = (int) $term->tid;
        }
      }
    }
    node_save($node);
  }
}

/**
 * Initializes term reference fields for the vocabulary.
 *
 * @param $vocabulary
 *   Vocabulary.
 *
 * @throws \Exception
 * @throws \FieldException
 */
function mt_import_initialize_vocabulary_fields($vocabulary) {
  // Step 1. Create fields for application node, if don't exist.
  $application_field = "field_app_{$vocabulary->machine_name}";

  if (!field_info_field($application_field)) {
    $field_base = array(
      'field_name' => $application_field,
      'type' => 'taxonomy_term_reference',
      'cardinality' => -1,
      'entity_types' => array(),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => $vocabulary->machine_name,
            'parent' => 0,
          ),
        ),
      ),
    );
    field_create_field($field_base);
  }

  if (!field_info_instance('node', $application_field, 'application')) {
    // Create category field instance if does not exist.
    $instance = array(
      'field_name' => $application_field,
      'label' => $vocabulary->name,
      'entity_type' => 'node',
      'bundle' => 'application',
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
      ),
    );
    field_create_instance($instance);
  }

  // Step 2. Create category field in vocabularies, if doesn't exist.
  $field_name = 'field_category';

  if (!field_info_field($field_name)) {
    $categories_vocabulary = mt_import_taxonomy_vocabulary_load_or_create_by_title('Categories');
    $field_base = array(
      'field_name' => $field_name,
      'type' => 'taxonomy_term_reference',
      'cardinality' => -1,
      'entity_types' => array(),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => $categories_vocabulary->machine_name,
            'parent' => 0,
          ),
        ),
      ),
    );
    field_create_field($field_base);
  }

  if (!field_info_instance('taxonomy_term', $field_name, $vocabulary->machine_name)) {
    // Create category field instance if does not exist.
    $instance = array(
      'field_name' => $field_name,
      'label' => 'Category',
      'entity_type' => 'taxonomy_term',
      'bundle' => $vocabulary->machine_name,
      'required' => 1,
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 1,
      ),
    );
    field_create_instance($instance);
  }

  // Step 3. Create double field for software selection, if doesn't exist.
  $selection_field = "field_s_{$vocabulary->machine_name}";

  if (!field_info_field($selection_field)) {
    $field_base = array(
      'field_name' => $selection_field,
      'type' => 'double_field',
      'cardinality' => -1,
      'entity_types' => array(),
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
    );
    field_create_field($field_base);
  }

  if (!field_info_instance('node', $selection_field, 'application')) {
    // Create selection field instance if does not exist.
    $instance = array(
      'field_name' => $selection_field,
      'label' => $vocabulary->name,
      'bundle' => 'software_selection',
      'entity_type' => 'node',
      'widget' => array(
        'active' => 1,
        'module' => 'double_field',
        'type' => 'textfield_&_textfield',
        'settings' => array(
          'first' => array(
            'general' => array(
              'prefix' => '',
              'required' => 1,
              'suffix' => '',
            ),
            'textfield' => array(
              'placeholder' => '',
              'size' => 10,
            ),
          ),
          'inline' => 1,
          'second' => array(
            'general' => array(
              'prefix' => '',
              'required' => 1,
              'suffix' => '',
            ),
            'textfield' => array(
              'placeholder' => '',
              'size' => 10,
            ),
          ),
        ),
      ),
    );
    field_create_instance($instance);
  }
}

/**
 * Gets import contents.
 *
 * @return array
 *   The import data grouped by sheet names.
 *
 * @throws \PHPExcel_Exception
 * @throws \PHPExcel_Reader_Exception
 */
function mt_import_get_contents() {
  require_once DRUPAL_ROOT . '/../vendor/autoload.php';
  $file_name = drupal_get_path('module', 'mt_import') . '/import/import.xlsx';
  $reader = PHPExcel_IOFactory::createReaderForFile($file_name);
  $reader->setReadDataOnly();

  $excel_object = $reader->load($file_name);
  $worksheetNames = $excel_object->getSheetNames($file_name);
  $results = array();
  foreach($worksheetNames as $key => $sheet_name){
    // Set the current active worksheet by name.
    $excel_object->setActiveSheetIndexByName($sheet_name);
    // Create an assoc array with the sheet name as key and the sheet contents
    // array as value.
    $results[$sheet_name] = $excel_object->getActiveSheet()->toArray(NULL, TRUE, TRUE, TRUE);
  }

  return $results;
}

/**
 * Creates a machine name from text.
 *
 * @param $name
 *   Text.
 *
 * @return string
 *   Machine name.
 */
function mt_import_get_machine_name($name) {
  return preg_replace('@[^a-z0-9-]+@','_', strtolower($name));
}

/**
 * Loads vocabulary by title, or creates if does not exist.
 *
 * @param $title
 *   Title.
 *
 * @return object
 *   Vocabulary.
 */
function mt_import_taxonomy_vocabulary_load_or_create_by_title($title) {
  // Remove 'functions' from title as name get's too long.
  $machine_name = mt_import_get_machine_name(str_replace(' functions', '', $title));
  if (!$vocabulary = taxonomy_vocabulary_machine_name_load($machine_name)) {
    $vocabulary = (object) array(
      'name' => $title,
      'machine_name' => $machine_name,
    );
    taxonomy_vocabulary_save($vocabulary);
  }

  return $vocabulary;
}

/**
 * Loads term by name, or creates if does not exist.
 *
 * @param $name
 *   name.
 * @param $vocabulary
 *   Vocabulary.
 *
 * @return object
 *   Term.
 */
function mt_import_taxonomy_term_load_or_create_by_name($name, $vocabulary) {
  if ($term = taxonomy_get_term_by_name($name, $vocabulary->machine_name)) {
    $term = reset($term);
  }
  else {
    $term = (object) array(
      'name' => $name,
      'vid' => $vocabulary->vid,
    );
    taxonomy_term_save($term);
  }
  return $term;
}
