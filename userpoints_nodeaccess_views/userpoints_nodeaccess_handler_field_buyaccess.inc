<?php
// $Id: uc_product_handler_field_buyitnow.inc,v 1.1.2.3 2009/05/07 20:52:29 islandusurper Exp $

/**
 * @file
 * Views handler: Simpler "Add to cart" form as a field.
 */

/**
 * Display the simpler Add to cart form like the catalog.
 */
class userpoints_nodeaccess_handler_field_buyaccess extends views_handler_field {
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  public function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['nid'] = array('table' => 'node', 'field' => 'nid');
  }

  function element_type() {
    if (isset($this->definition['element type'])) {
      return $this->definition['element type'];
    }
    return 'div';
  }

  function render($values) {
    global $user;

    $node = node_load($values->nid);

    // Check if node type is enabled and node as points assigned.
    if (empty($node->userpoints_nodeaccess_points_price) || !variable_get('userpoints_nodeaccess_enabled_' . $node->type, variable_get('userpoints_nodeaccess_enabled', TRUE))) {
      return t('No points required');
    }

    // Don't limit access to users with bypass permission or the author.
    if ($bypass_access = user_access('bypass node access')) {
      return t('Unlimited access');
    }

    // Check author access.
    if ($node->uid == $user->uid) {
      return t('Author access granted.');
    }

    // Check if user already has access.
    if (userpoints_nodeaccess_has_access($values->nid, $user->uid)) {
      return t('Access granted');
    }

    // Check if user is allowed to trade points.
    if (!user_access('trade userpoints for node access')) {
      return t('Access denied');
    }

    $current_points = userpoints_get_current_points($user->uid, $node->userpoints_nodeaccess_points_category);
    $categories = userpoints_get_categories();
    $category = $categories[$node->userpoints_nodeaccess_points_category];

    // Check if user has enough points.
    if ($current_points < $node->userpoints_nodeaccess_points_price) {
      return t('Need more points.');
    }

    return drupal_render(drupal_get_form('userpoints_nodeaccess_trade_access_form', $node, $current_points, $category, TRUE));
  }
}
