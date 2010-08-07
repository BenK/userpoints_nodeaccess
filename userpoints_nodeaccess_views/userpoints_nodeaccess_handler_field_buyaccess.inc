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

  function element_type() {
    if (isset($this->definition['element type'])) {
      return $this->definition['element type'];
    }
    return 'div';
  }

  function render($values) {
    $node = node_load($values->nid);
    return drupal_get_form('userpoints_nodeaccess_buy_access_form_'. $values->nid, $node);
    //drupal_set_message($values->nid);
    //return 'div';
  }
}
