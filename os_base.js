;(function ($) {
  // Adapted from Open Atrium: http://openatrium.com
  Drupal.behaviors.osBase = function (context) {
    // Drop-down blocks
    $('.dropdown-block:not(.processed)')
      .addClass('processed')
      .each(function() {
        $('.title', this).click(function(event) {
          // don't travel to the link location, if any
          event.preventDefault();
          if (!$(this).is('.toggle-active')) {
            // Deactivate all drop down blocks
            $('.dropdown-block .title').removeClass('toggle-active');
            $('.dropdown-block .content').hide();

            // Activate this dropdown
            $(this).addClass('toggle-active').siblings('.content').show();

            // if there's a form inside our drop-down, focus its first input
            $(this).siblings('.content').find('input:first').focus();
          }
          else {
            $(this).removeClass('toggle-active').siblings('.content').hide();
          }
          return false;
        });
      });
  };
})(jQuery);
