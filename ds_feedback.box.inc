<?php

/**
 * Implementation of hook_default_box().
 */
function ds_feedback_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ds_feedback';
  $box->plugin_key = 'ds_feedback_box';
  $box->title = 'Feedback';
  $box->description = 'Feedback';
  $box->options = array(
    'body' => 'Please report any inconsistencies, apparent data errors, or other comments on this page.',
    'format' => '3',
    'button_title' => 'Send feedback',
  );

  $export['ds_feedback'] = $box;
  return $export;
}
