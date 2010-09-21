<?php

/**
 * Implementation of hook_user_default_roles().
 */
function os_base_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
  );

  // Exported role: site editor
  $roles['site editor'] = array(
    'name' => 'site editor',
  );

  return $roles;
}
