// Adapted from Open Atrium: http://openatrium.com
Drupal.behaviors.osBase = function (context) {
  // Drop-down blocks
  $('div.dropdown-blocks:not(.processed)')
    .addClass('processed')
    .each(function() {
      $('.block-title', this).click(function() {
        if (!$(this).is('.toggle-active')) {
          $('div.dropdown-blocks .block-title').removeClass('toggle-active');
          $('div.dropdown-blocks div.block-toggle div.block-content').hide();
          $(this).addClass('toggle-active').siblings('div.block-content').show();
        }
        else {
          $(this).removeClass('toggle-active').siblings('div.block-content').hide();
        }
        return false;
      });
    });
};
