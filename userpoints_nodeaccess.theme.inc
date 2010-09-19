<?php
// $Id$

/**
 * @file
 * Theme functions for userpoints_nodeaccess.module
 */

function theme_userpoints_nodeaccess_node_points_information($variables) {
  $args = array(
    '@category' => $variables['category'],
    '@points' => $variables['points'],
    '@price' => $variables['price'],
  );

  if ($variables['price'] <= $variables['points']) {
    return '<div class="userpoints-nodeaccess userpoints-nodeaccess-tradein" >' . t('Trade in @price !points to access this content. You have @points !points available. Only !points in the @category category may be used.', array_merge(userpoints_translation(), $args)) . '</div>';
  }
  else {
    return '<div class="userpoints-nodeaccess userpoints-nodeaccess-needmore" >' . t('@price !points are required to access this content. You currently have @points !points available and need more !points. Only !points in the @category category may be used.', array_merge(userpoints_translation(), $args));
  }
}
