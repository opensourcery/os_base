<?php
/**
 * @file
 * os_base.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function os_base_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'basic_page_banner_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Basic Page Banner Image';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Banner image */
  $handler->display->display_options['fields']['field_page_banner']['id'] = 'field_page_banner';
  $handler->display->display_options['fields']['field_page_banner']['table'] = 'field_data_field_page_banner';
  $handler->display->display_options['fields']['field_page_banner']['field'] = 'field_page_banner';
  $handler->display->display_options['fields']['field_page_banner']['label'] = '';
  $handler->display->display_options['fields']['field_page_banner']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_page_banner']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_page_banner']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_page_banner']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_banner']['settings'] = array(
    'image_style' => 'page-banner',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_page_banner']['field_api_classes'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['basic_page_banner_image'] = $view;

  return $export;
}
