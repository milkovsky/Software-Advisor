<?php

namespace Drupal\software_advisor;

/**
 * Main class for controlling software advices.
 */
class SoftwareAdvisor {

  /**
   * The software selection node.
   *
   * @var \stdClass
   */
  protected $node;

  /**
   * The software suggestions.
   *
   * @var int[]
   */
  protected $suggestions = array();

  /**
   * Used for static cache of functions tree.
   *
   * @var int[]
   */
  protected $functionsTree = array();

  /**
   * Used for static cache of application functions tree.
   *
   * @var int[]
   */
  protected $applicationFunctionsTree = array();

  /**
   * Used for static cache of rates.
   *
   * @var int[]
   */
  protected $ratesTree = array();

  /**
   * Constructs the object.
   *
   * @param \stdClass $node
   *  The software selection node.
   *
   * @return static
   */
  public static function create(\stdClass $node) {
    return new static($node);
  }

  /**
   * Constructs the object.
   *
   * @param \stdClass $node
   *   The software selection node.
   */
  protected function __construct(\stdClass $node) {
    $this->node = $node;
  }

  /**
   * Returns the software selection node.
   *
   * @return \stdClass
   *   The software selection node
   */
  public function getEntity() {
    return $this->node;
  }

  /**
   * Returns the software suggestions for selection.
   *
   * @return array
   *   The software suggestions
   */
  public function getSuggestions() {
    $this->calculateSuggestions();
    return $this->suggestions;
  }

  /**
   * Calculates software suggestions.
   */
  public function calculateSuggestions() {
    if (empty($this->suggestions)) {
      $suggestions = array();
      $ratings = array();

      $rates = $this->getRatesTree();
      $applications = $this->getAllApplications();

      foreach ($rates as $business_process => $values) {
        foreach ($applications as $nid => $application) {
          $rating = $this->rateApplication($application, $values, $business_process);
          if ($rating >= SOFTWARE_ADVISOR_SUGGESTIONS_SCORE_MIN) {
            $ratings[$business_process][$nid] = $rating;
          }
        }

        // Get suggestions from rating.
        arsort($ratings[$business_process]);
        $i = 0;
        foreach($ratings[$business_process] as $nid => $rating) {
          if ($i >= SOFTWARE_ADVISOR_SUGGESTIONS_NUMBER) {
            break;
          }
          $suggestions[$business_process][$nid] = $rating;
          $i++;
        }
      }

      $this->suggestions = $suggestions;
    }
  }

  /**
   * Gets functions tree.
   *
   * @param string $business_process
   *   Business process
   *
   * @return string[]
   *   Functions tree.
   */
  protected function getFunctionsTree($business_process) {
    if (empty($this->functionsTree[$business_process])) {
      $this->functionsTree[$business_process] = SoftwareAdvisorUtil::getFunctionsTree($business_process);
    }
    return $this->functionsTree[$business_process];
  }

  /**
   * Rates application.
   *
   * @param \stdClass $application
   *   Application node.
   * @param array $values
   *   Rate values.
   * @param string $business_process
   *   Business process name.
   *
   * @return int
   *   Application rate.
   */
  protected function rateApplication(\stdClass $application, array $values, $business_process) {
    $rating = 0;
    $max_rating = 0;

    $functions_tree = $this->getFunctionsTree($business_process);
    $application_functions = $this->getApplicationFunctions($application, $business_process);

    foreach ($functions_tree as $category => $functions) {
      // Skip category is there is no value.
      if (empty($values[$category])) {
        continue;
      }

      $category_rating = 0;
      $max_category_rating = 0;
      foreach (array_keys($functions) as $function) {
        // Check if application has function and function is rated.
        if (!empty($values[$function])) {
          $max_category_rating += $values[$function];
          if (!empty($application_functions[$function])) {
            $category_rating += $values[$function];
          }
        }
      }
      // Correct category rating according to the category rate value.
      $category_rating *= $values[$category] / SOFTWARE_ADVISOR_RATE_MAX;
      $max_category_rating *= $values[$category] / SOFTWARE_ADVISOR_RATE_MAX;

      // @todo Detailed rate by category.
      $rating += $category_rating;
      $max_rating += $max_category_rating;
    }

    // Convert rating to percentage.
    return number_format($rating / $max_rating * 100, 2);
  }

  /**
   * Gets all the application nodes.
   *
   * @return \stdClass[]
   *   Application nodes.
   */
  protected function getAllApplications() {
    /* @var \stdClass[] $nodes */
    $nodes = entity_load('node', FALSE, array('type' => 'application'));
    return $nodes;
  }

  /**
   * Gets rates grouped by business process.
   *
   * @return array
   */
  protected function getRatesTree() {
    if (empty($this->ratesTree)) {
      $entity = $this->getEntity();
      $rates = array();
      foreach ($entity as $field => $values) {
        if (!empty($values) && strpos($field, 'field_s_') !== FALSE) {
          $business_process = str_replace('field_s_', '', $field);
          foreach ($entity->{$field}[LANGUAGE_NONE] as $value) {
            $rates[$business_process][$value['first']] = $value['second'];
          }
        }
      }
      $this->ratesTree = $rates;
    }

    return $this->ratesTree;
  }

  /**
   * Gets application functions
   *
   * @param \stdClass $application
   *   Application node.
   * @param string $business_process
   *   Business process name.
   *
   * @return int[]
   *   Application function term ids.
   */
  protected function getApplicationFunctions(\stdClass $application, $business_process) {
    if (empty($this->applicationFunctionsTree[$application->nid][$business_process])) {
      $field = "field_app_{$business_process}";
      $functions = array();
      if (!empty($application->{$field}[LANGUAGE_NONE])) {
        foreach ($application->{$field}[LANGUAGE_NONE] as $value) {
          $functions[$value['tid']] = $value['tid'];
        }
      }
      $this->applicationFunctionsTree[$application->nid][$business_process] = $functions;
    }
    return $this->applicationFunctionsTree[$application->nid][$business_process];
  }

  /**
   * Generates render array for suggestions.
   *
   * @todo Convert HTML to templates to not depend on the bootstrap classes.
   *
   * @return string[]
   *   Render array.
   */
  public function generateSuggestionsRenderArray() {
    $suggestions = $this->getSuggestions();
    $output = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('suggestions')),
    );

    foreach ($suggestions as $business_process => $applications) {
      $rank = 0;
      $rows = array();

      // Header, row with score, row with general data.
      $header = array(t('Characteristic name'), t('Your choices'));
      $row_score = array(t('Score'), '');
      $row_general_data = array(t('General data'), '');
      foreach ($applications as $nid => $score) {
        $rank++;
        $class = 'odd';
        if ($rank % 2 == 0) {
          $class = 'even';
        }
        $header[] = $this->generateRankHtml($rank);

        $node = node_load($nid);
        $view = entity_view('node', array($node), 'teaser');
        $view = reset($view['node']);
        $row_general_data[] = array(
          'data' => render($view),
          'class' => array($class),
        );
        $row_score[] = array(
          'data' => "<span class=\"badge\">$score%</span>",
          'class' => array($class),
        );
      }
      $rows[] = $row_score;
      $rows[] = $row_general_data;

      // Functions.
      $rates_tree = $this->getRatesTree();
      $rates = $rates_tree[$business_process];
      $functions_tree = $this->getFunctionsTree($business_process);
      foreach ($functions_tree  as $category_tid => $functions) {
        // Skip categories that were not chosen.
        if (empty($rates[$category_tid])) {
          continue;
        }

        // Category row.
        $term = taxonomy_term_load($category_tid);
        $row = array(
          '<strong>' . $term->name . '</strong>',
          $this->convertRateToText($rates[$category_tid]),
          array(
            'data' => '',
            'colspan' => count($applications),
          ),
        );
        $rows[] = $row;

        // Category function rows.
        foreach ($functions as $tid => $name) {
          // Skip functions that were not chosen.
          if (empty($rates[$tid])) {
            continue;
          }

          $row = array($name, $this->convertRateToText($rates[$tid]));
          $rank = 0;
          foreach ($applications as $nid => $score) {
            $rank++;
            $class = 'odd';
            if ($rank % 2 == 0) {
              $class = 'even';
            }

            $application = node_load($nid);
            $app_functions = $this->getApplicationFunctions($application, $business_process);
            if (!empty($app_functions[$tid])) {
              $row[] = array(
                'data' => '<span class="text-success glyphicon glyphicon-ok"></span>',
                'class' => array($class, 'suggestion-function-exists'),
              );
            }
            else {
              $row[] = array(
                'data' => '<span class="text-muted glyphicon glyphicon-remove"></span>',
                'class' => array($class, 'suggestion-function-absent'),
              );
            }
          }
          $rows[] = $row;
        }
      }

      $vocabulary = taxonomy_vocabulary_machine_name_load($business_process);
      $business_process_name = str_replace(' functions', '', $vocabulary->name);
      $output['content'][$business_process] = array(
        '#type' => 'container',
        'content' => array(
          '#markup' => "<h2>{$business_process_name} suggestions</h2>"
        ),
        'results' => array(
          '#theme' => 'table',
          '#header' => $header,
          '#rows' => $rows,
        ),
      );
    }

    return $output;
  }

  /**
   * Converts rate to text.
   *
   * @param int $rate
   *   Rate value.
   * @param boolean $append_rate_number
   *   (optional) Appends rate value before text.
   *
   * @return string
   *   Rate text.
   */
  public static function convertRateToText($rate, $append_rate_number = TRUE) {
    $text = '';

    switch ((int) $rate) {
      case 0:
        $text = 'Not needed';
        break;
      case 1:
        $text = 'Almost unimportant';
        break;
      case 2:
        $text = 'Slightly important';
        break;
      case 3:
        $text = 'Important';
        break;
      case 4:
        $text = 'Very important';
        break;
      case 5:
        $text = 'Highly important';
        break;
    }

    if ($append_rate_number) {
      $text = "<span class=\"badge\">$rate</span> <small class=\"text-muted\">$text</small>";
    }
    return $text;
  }

  /**
   * Generates HTML for rank.
   *
   * @param int $rank
   *   Rank value.
   *
   * @return string
   *   Rank HTML.
   */
  protected function generateRankHtml($rank) {
    $text = '';
    switch ((int) $rank) {
      case 1:
        $text = "<span class=\"glyphicon glyphicon-king\"></span>";
        break;
      /*case 2:
        $text = "<span class=\"glyphicon glyphicon-queen\"></span>";
        break;
      case 3:
        $text = "<span class=\"glyphicon glyphicon-tower\"></span>";
        break;
      case 4:
        $text = "<span class=\"glyphicon glyphicon-knight\"></span>";
        break;
      default:
        $text = "<span class=\"glyphicon glyphicon-pawn\"></span>";
        break;*/
    }

    return "#$rank Rank $text";
  }

}
