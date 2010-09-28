<?php
// $Id$

/**
 * User starting point block.
 */
function _os_base_block_account() {
  $block = array();
  $block['subject'] = '';

  if (!user_is_anonymous()) {
    $block['content'] = "<div class='user-account-menu block-toggle'>";
    $block['content'] .= "<div class='block-title'><h3>". t('My account') ."</h3></div>";
    $block['content'] .= "<div class='block-content clear-block'>". theme('links', os_base_account_links()) ."</div>";
    $block['content'] .= "</div>";
    return $block;
  }
  else {
    $item = menu_get_item('user/login');
    if ($item && $item['access']) {
      return array('content' => l($item['title'], $item['href']));
    }
  }
}

/**
 * Generates an array of account links suitable for use in theme_links().
 */
function os_base_account_links() {
  global $user;
  $links = array();

  $paths = array(
    "user/{$user->uid}" => t('Profile'),
    "user/{$user->uid}/edit" => '',
    'logout' => '',
  );

  foreach ($paths as $path => $title) {
    $item = menu_get_item($path);
    if ($item && $item['access']) {
      $links[] = array(
        'title' => !empty($title) ? $title : $item['title'],
        'href' => $item['href'],
      );
    }
  }
  drupal_alter('os_base_account_links', $links);
  return $links;
}
