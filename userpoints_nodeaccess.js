// $Id$

(function ($) {

  Drupal.behaviors.userpointsNodeAccessFieldsetSummaries = {
    attach: function (context) {
      $('fieldset.userpoints-nodeaccess-form', context).drupalSetSummary(function (context) {
        if ($('#edit-points-price', context).val() > 0) {
          var params = {
            '@points': $('#edit-points-price', context).val(),
            '@category': $('select#edit-points-category :selected', context).text()
          };
          return Drupal.t('@points in category @category required.', params);
        }
        else {
          return Drupal.t('No points required.');
        }
      });
    }
  };

})(jQuery);
