<?php

/**
 * @file
 * Proves the administrative related functions for the Formula 1 Feed Module
 */

function f1_feed_block_settings_form() {
  $form = array();
  $form['f1_feed_block_maxposts'] = array(
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
  return system_settings_form($form);
}

function f1_feed_block_settings_form_validate($form, &$form_state){
  $maxposts = $form_state['values']['f1_feed_block_maxposts'];
  if(!is_numeric($maxposts)) {
    form_set_error('f1_feed_block_maxposts', t('You must enter an integer for the maximum number of links.'));
  }
  else if ($maxposts <= 0) {
    form_set_error('f1_feed_block_maxposts', t('Maximum number of links must be postive.'));
    }
  }
