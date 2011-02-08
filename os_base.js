;(function ($) {
  // Adapted from Open Atrium: http://openatrium.com
  Drupal.behaviors.osBase = function (context) {
    // Drop-down blocks
    $('.dropdown-block:not(.processed)', context)
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

    // Close dropdown blocks if a click lands outside of them
    // If an event gets to the body
    $('body:not(.os_base-processed)', context)
      .addClass('os_base-processed')
      .click(function() {
        $('.dropdown-block > .content').hide().siblings().removeClass('toggle-active');
      });

    // Prevent events from getting past the dropdown
    $('.dropdown-block > .content:not(.os_base-processed)', context)
      .addClass('os_base-processed')
      .click(function(e) {
        e.stopPropagation();
      });
  };
})(jQuery);
