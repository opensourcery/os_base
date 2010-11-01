<?php
// $Id$

/**
 * User starting point block.
 */
function _os_base_block_account() {
  $block = array();
  $block['subject'] = '';

  // build a dropdown block which reveals either a log in form or a list of
  // account/user related links.
  if (user_is_anonymous()) {
    $class = 'log-in';
    $item = menu_get_item('user/login');
    $content = drupal_get_form('user_login');
  }
  else {
    $class = 'my-account';
    $item = menu_get_item('user');
    $item['title'] = t('My account');
    $content = '';
  }

  if ($item && $item['access']) {
    $title = l($item['title'], $item['href']);

    $content .= theme('links', os_base_account_links($options));
    $block['content'] = "<div class='user-account-menu {$class} block-toggle'>";
    $block['content'] .= "<div class='block-title'><h3>{$title}</h3></div>";
    $block['content'] .= "<div class='block-content clear-block'>{$content}</div>";
    $block['content'] .= "</div>";
  }
  return $block;
}

/**
 * Generates an array of account links suitable for use in theme_links().
 */
function os_base_account_links() {
  global $user;

  if (user_is_anonymous()) {
    $paths = array(
      'user/register' => t('Create new account'),
      'user/password' => t('Forgot password?'),
    );
    $hook = 'os_base_account_links_anonymous';
  }
  else {
    $paths = array(
      "user/{$user->uid}" => t('Profile'),
      "user/{$user->uid}/edit" => '',
      'logout' => '',
    );
    $hook = 'os_base_account_links';
  }

  $links = array();
  foreach ($paths as $path => $title) {
    $item = menu_get_item($path);
    if ($item && $item['access']) {
      $links[] = array(
        'title' => !empty($title) ? $title : $item['title'],
        'href' => $item['href'],
      );
    }
  }
  drupal_alter($hook, $links);
  return $links;
}

