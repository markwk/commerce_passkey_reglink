<?php

/**
 * @file
 * Builds placeholder replacement tokens for passkey related information.
 */

/**
 * Implements hook_token_info().
 */
function commerce_passkey_reglink_token_info() {
  $order = array();
  $order['passkey-reservation-link'] = array(
    'name' => t('Passkey Reservation Link'),
    'description' => t('Passkey reservation link to be used in email'),
  );
  return array(
    'tokens' => array('commerce-order' => $order),
  );
}

/**
 * Implements hook_tokens().
 */
function commerce_passkey_reglink_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    $order = $data['commerce-order'];
    $link = commerce_passkey_reglink_bridge_link($order);
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'passkey-reservation-link':
          $replacements[$original] = theme('commerce_passkey_reglink_link', array('link' => $link));
          break;
      }
    }
  }

  return $replacements;
}