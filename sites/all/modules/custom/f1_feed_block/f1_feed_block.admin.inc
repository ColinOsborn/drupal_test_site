<?php

/**
 * @file
 * Proves the administrative related functions for the Formula 1 Feed Module
 */

function f1_feed_block_settings_form() {
  $form = array();
  $form['fb_feed_block_maxposts'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Formula 1 Feed items to show'),
    '#description' => t('The maximum number of Formula 1 Feed item nodes to show in the Formula 1 Feeds block.'),
    '#default_value' => variable_get('f1_feed_block_maxposts', 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
  );
  $form['f1_feed_block_types'] = array(
    '#title' => t('The content types to enable FB Feed block for'),
    "#description" => t('On the specified content types a F1 Feed Block option will be enabled.'),
    '#type' => 'checkboxes',
    '#options' => node_type_get_name(),
    '#default_value' => variable_get('f1_feed_block_types', array()),
    '#required' => TRUE,
  );
}
