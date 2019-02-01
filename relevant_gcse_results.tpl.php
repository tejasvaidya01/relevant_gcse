<?php
?>

<?php if ($prefix): ?>
  <div class="google-cse-results-prefix"><?php print $prefix; ?></div>
<?php endif; ?>

<div id="expansion"></div>

<div id="cse3">Loading entities.....</div>

<?php if ($results_searchbox_form): ?>
  <?php print render($results_searchbox_form); ?>
<?php endif; ?>

<div id="google-cse-results">
  <noscript>
    <?php print $noscript; ?>
  </noscript>
</div>

<?php if ($suffix): ?>
  <div class="google-cse-results-suffix"><?php print $suffix; ?></div>
<?php endif; ?>
