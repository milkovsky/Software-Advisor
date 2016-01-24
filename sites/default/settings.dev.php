<?php

include_once 'settings.base.php';

// Master.
/*$conf['master_modules']['dev'] = array(

);*/
$conf['master_current_scope'] = 'dev';

// Database.
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'master-thesis',
      'username' => 'root',
      'password' => '',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
