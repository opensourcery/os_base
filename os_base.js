// Adapted from Open Atrium: http://openatrium.com
Drupal.behaviors.osBase = function (context) {
  // Drop-down blocks
  $('div.dropdown-blocks:not(.processed)')
    .addClass('processed')
    .each(function() {
      $('.block-title', this).click(function(event) {
        // don't travel to the link location, if any
        event.preventDefault();
        if (!$(this).is('.toggle-active')) {
          $('div.dropdown-blocks .block-title').removeClass('toggle-active');
          $('div.dropdown-blocks div.block-toggle div.block-content').hide();
          $(this).addClass('toggle-active').siblings('div.block-content').show();

          // if there's a form inside our drop-down, focus its first input
          $(this).siblings('div.block-content').find('input:first').focus();
        }
        else {
          $(this).removeClass('toggle-active').siblings('div.block-content').hide();
        }
        return false;
      });
    });
};
