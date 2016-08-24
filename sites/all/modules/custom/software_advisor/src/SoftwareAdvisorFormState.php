<?php

/**
 * @file
 * Contains SoftwareAdvisorFormState.
 */

namespace Drupal\software_advisor;

/**
 * Class for accessing and holding selection state related information.
 *
 * This state is kept across multiple forms.
 */
class SoftwareAdvisorFormState implements \Serializable {

  /**
   * The user account of the user investing.
   *
   * @var \stdClass
   */
  public $user;

  /**
   * The selection entity.
   *
   * @var \stdClass
   */
  public $software_selection;

  /**
   * The class name of the currently active step.
   *
   * @var string
   */
  public $activeStep;

  /**
   * Creates a new selection form state at the beginning of a new selection.
   *
   * @param string $step
   *   The step class to start with.
   *
   * @return static
   */
  public static function create($step) {
    $state = new static();
    $state->activeStep = $step;
    $state->user = user_load($GLOBALS['user']->uid);
    $state->software_selection = entity_create('node', array('type' => 'software_selection'));
    $state->software_selection->uid = $state->user->uid;
    return $state;
  }

  /**
   * Constructs the object.
   */
  protected function __construct() {

  }

  /**
   * {@inheritdoc}
   */
  public function serialize() {
    // For the payment entity, we make sure to have the latest one as it gets
    // modified by the payment process also. So always re-load it by its ID
    // if possible.
    return serialize(array($this->activeStep, $this->user->uid, $this->software_selection));
  }

  /**
   * {@inheritdoc}
   */
  public function unserialize($serialized) {
    list($step_class, $uid, $software_advisor) = unserialize($serialized);

    if ($uid != $GLOBALS['user']->uid) {
      throw new \LogicException("This may not happen.");
    }

    $this->activeStep = $step_class;
    $this->user = user_load($uid);
    $this->software_selection = $software_advisor;
  }

}
