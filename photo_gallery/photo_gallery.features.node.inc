<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _photo_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Photo Gallery'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Photo Gallery'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'photo' => array(
      'name' => t('Photo'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Photo Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
