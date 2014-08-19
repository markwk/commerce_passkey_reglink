<?php

/**
 * @file
 * Default implementation of the passkey hotel reservation modification link
 *
 * Available variables:
 * - $link: Path for passkey reservation modification.
 * - $hotel_text: Hotel text reserved hotel.
 * - $link_text: Link text to modify reservation
 *
 * @see template_preprocess()
 * @see template_process()
 */
?>
<div class='commerce-passkey-reglink'>
	<h3><?php print $hotel_text; ?></h3>
  <p>
	  <a href="<?php print $link; ?>" target="_blank">
	    <i><?php print $link_text; ?></i>
	  </a>
	</p>
</div>