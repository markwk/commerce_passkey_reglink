<?php

/**
 * @file
 * Default rules configurations for Commerce Passkey RegLink.
 */


/**
 * Implements hook_default_rules_configuration().
 */
function commerce_passkey_reglink_default_rules_configuration() {
  $rules = array();
  $rule = rules_reaction_rule();

  $rule->label = t('Commerce Passkey RegLink Integration.');
  $rule->active = TRUE;

  $rule
    ->event('commerce_checkout_complete')
    ->action('commerce_passkey_reglink_get_bridge_record', array());

  $rules['commerce_passkey_reglink_integration'] = $rule;

  return $rules;
}