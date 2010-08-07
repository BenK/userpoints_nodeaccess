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

  $output = t('To access this content, you must trade in @price !points of the category @category. You currently have @points !points in the @category category.', array_merge(userpoints_translation(), $args));
  return '<div>' . $output . '</div>';
}