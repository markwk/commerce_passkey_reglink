<?php

/**
 * @file
 * Rules integration for the commerce passkey integration process.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_passkey_reglink_rules_action_info() {
  $actions = array();

  $actions['commerce_passkey_reglink_get_bridge_record'] = array(
    'label' => t('Get Passkey RegLink Bridge ID and Save in Order.'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order in checkout'),
      ),
    ),
    'group' => t('Commerce Checkout'),
    'callbacks' => array(
      'execute' => 'commerce_passkey_reglink_rules_complete_checkout',
    ),
  );

  return $actions;
}

/**
 * Action callback: completes checkout for the given order.
 */
function commerce_passkey_reglink_rules_complete_checkout($order) {
	$bridgeId = commerce_passkey_reglink_api_request($order);
	$order->field_passkey_bridgeid['und'][0]['value'] = $bridgeId;
	commerce_order_save($order);
}