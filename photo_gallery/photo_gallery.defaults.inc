<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _photo_gallery_content_default_fields() {
  $fields = array();

  // Exported field: field_gallery
  $fields[] = array(
    'field_name' => 'field_gallery',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'gallery' => 'gallery',
      'front' => 0,
      'lyrics' => 0,
      'page' => 0,
      'photo' => 0,
      'story' => 0,
      'image' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Add Photo',
        'hover_title' => '',
        'destination' => 'node',
      ),
      'fallback' => 'select',
      'edit_fallback' => NULL,
      'label' => 'gallery',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_image
  $fields[] = array(
    'field_name' => 'field_image',
    'type_name' => 'photo',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'gallery',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => 'Texcentrics',
      'custom_alt' => 1,
      'title' => 'Texcentrics Photo',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'image',
      'weight' => 0,
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('gallery'),
    t('image'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _photo_gallery_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _photo_gallery_imagecache_default_presets() {
  $items = array(
    'full' => array(
      'presetname' => 'full',
      'actions' => array(),
    ),
    'small_gallery' => array(
      'presetname' => 'small_gallery',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '220',
            'height' => '140',
          ),
        ),
      ),
    ),
    'space_gallery' => array(
      'presetname' => 'space_gallery',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '450',
            'height' => '300',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _photo_gallery_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_photo';
  $strongarm->value = array(
    'title' => '-5',
    'menu' => '-2',
  );

  $export['content_extra_weights_photo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_class_id';
  $strongarm->value = '.imagecache-small_gallery';

  $export['fancybox_class_id'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_easingin';
  $strongarm->value = 'easeOutBack';

  $export['fancybox_easingin'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_easingout';
  $strongarm->value = 'easeInBack';

  $export['fancybox_easingout'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_files';
  $strongarm->value = array(
    'js' => 'jquery.fancybox-1.3.1.js',
    'css' => 'jquery.fancybox-1.3.1.css',
  );

  $export['fancybox_files'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_hideoncontentclick';
  $strongarm->value = 'true';

  $export['fancybox_hideoncontentclick'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_icache_large';
  $strongarm->value = 'photo';

  $export['fancybox_icache_large'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_icache_small';
  $strongarm->value = 'small_gallery';

  $export['fancybox_icache_small'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_overlayopacity';
  $strongarm->value = '.4';

  $export['fancybox_overlayopacity'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_overlayshow';
  $strongarm->value = 'true';

  $export['fancybox_overlayshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_padding';
  $strongarm->value = '0';

  $export['fancybox_padding'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_path';
  $strongarm->value = 'sites/all/libraries/fancybox';

  $export['fancybox_path'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_settings';
  $strongarm->value = array(
    'options' => array(
      'width' => '425',
      'height' => '355',
      'padding' => 10,
      'margin' => 20,
      'titleShow' => 1,
      'titlePosition' => 'inside',
      'scrolling' => 'auto',
      'showCloseButton' => 1,
      'showNavArrows' => 1,
      'cyclic' => 1,
      'opacity' => 0,
      'overlayShow' => 1,
      'overlayColor' => '#666',
      'overlayOpacity' => '0.3',
      'hideOnOverlayClick' => 0,
      'hideOnContentClick' => 1,
      'enableEscapeButton' => 1,
      'centerOnScroll' => 0,
      'autoScale' => 0,
      'easingIn' => 'swing',
      'easingOut' => 'swing',
      'changeFade' => 'fast',
      'changeSpeed' => 300,
      'transitionIn' => 'fade',
      'speedIn' => 300,
      'transitionOut' => 'fade',
      'speedOut' => 300,
      'onStart' => '',
      'onComplete' => '',
      'onClosed' => '',
      'onCleanup' => '',
      'onCancel' => '',
    ),
    'activation' => array(
      'selector' => '',
      'activation_type' => 'exclude',
      'activation_pages' => 'admin*
            img_assist*
            node/add/*
            node/*/edit',
    ),
    'imagefield' => array(
      'grouping' => '1',
      'imagecache_preset' => 'full',
      'use_node_title' => 1,
    ),
  );

  $export['fancybox_settings'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_zoomopacity';
  $strongarm->value = 'true';

  $export['fancybox_zoomopacity'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_zoomspeedchange';
  $strongarm->value = '300';

  $export['fancybox_zoomspeedchange'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_zoomspeedin';
  $strongarm->value = '300';

  $export['fancybox_zoomspeedin'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fancybox_zoomspeedout';
  $strongarm->value = '300';

  $export['fancybox_zoomspeedout'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_delete';
  $strongarm->value = 0;

  $export['imagefield_import_delete'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_exif_body';
  $strongarm->value = 'ImageDescription';

  $export['imagefield_import_exif_body'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_exif_title';
  $strongarm->value = 'FileName';

  $export['imagefield_import_exif_title'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_field';
  $strongarm->value = 'photo:::field_image';

  $export['imagefield_import_field'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_ignore';
  $strongarm->value = '';

  $export['imagefield_import_ignore'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_iptc_body';
  $strongarm->value = '2#120';

  $export['imagefield_import_iptc_body'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_iptc_title';
  $strongarm->value = '2#005';

  $export['imagefield_import_iptc_title'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_mode';
  $strongarm->value = '0';

  $export['imagefield_import_mode'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_path';
  $strongarm->value = 'C:\\Users\\Public\\Pictures';

  $export['imagefield_import_path'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_prepopulate_title';
  $strongarm->value = '1';

  $export['imagefield_import_prepopulate_title'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_show_form';
  $strongarm->value = 1;

  $export['imagefield_import_show_form'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_show_thumbnails';
  $strongarm->value = 1;

  $export['imagefield_import_show_thumbnails'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_status';
  $strongarm->value = 0;

  $export['imagefield_import_status'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_thumbnail_width';
  $strongarm->value = '100';

  $export['imagefield_import_thumbnail_width'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagefield_import_unpublish';
  $strongarm->value = '';

  $export['imagefield_import_unpublish'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_gallery';
  $strongarm->value = array(
    '0' => 'status',
  );

  $export['node_options_gallery'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_photo';
  $strongarm->value = array(
    '0' => 'status',
  );

  $export['node_options_photo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 1,
    'toggle_favicon' => 1,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'toggle_node_info_author' => 0,
    'toggle_node_info_blog_post' => 0,
    'toggle_node_info_book' => 0,
    'toggle_node_info_page' => 0,
    'toggle_node_info_photo' => 0,
    'toggle_node_info_gallery' => 0,
    'toggle_node_info_story' => 0,
    'toggle_node_info_review' => 0,
    'toggle_node_info_video' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
  );

  $export['theme_settings'] = $strongarm;
  return $export;
}
