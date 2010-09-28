Drupal.behaviors.osBase = function (context) {
  // Togglable blocks
  $('div.toggle-blocks:not(.processed)')
    .addClass('processed')
    .each(function() {
      $('.block-title', this).click(function() {
        if (!$(this).is('.toggle-active')) {
          $('div.toggle-blocks .block-title').removeClass('toggle-active');
          $('div.toggle-blocks div.block-toggle div.block-content').hide();
          $(this).addClass('toggle-active').siblings('div.block-content').show();
        }
        else {
          $(this).removeClass('toggle-active').siblings('div.block-content').hide();
        }
        return false;
      });
    });
};
