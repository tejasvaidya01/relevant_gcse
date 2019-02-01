<?php

/**
 * @file
 * Admin settings for Google Custom Search Engine.
 */

/**
 * Admin settings page for the CSE.
 */
function relevant_gcse_admin_settings() {
  $form = array();
  $form['relevant_gcse'] = array(
    '#title' => t('Google CSE'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['relevant_gcse']['relevant_gcse_cx'] = array(
    '#title' => t('Google Custom Search Engine ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_cx', ''),
    '#description' => t('Enter your <a target="_blank" href="http://www.google.com/cse/manage/all">Google CSE unique ID</a> (click on control panel).'),
  );
  $form['relevant_gcse']['relevant_gcse_results_tab'] = array(
    '#title' => t('Search results tab name'),
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#size' => 60,
    '#description' => t('Enter a custom name of the tab where search results are displayed (defaults to %google).', array('%google' => t('Google'))),
    '#default_value' => variable_get('relevant_gcse_results_tab', ''),
  );
  $form['relevant_gcse']['relevant_gcse_results_width'] = array(
    '#title' => t('Search results frame width'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 6,
    '#description' => t('Enter the desired width, in pixels, of the search frame.'),
    '#default_value' => variable_get('relevant_gcse_results_width', 600),
  );
  $form['relevant_gcse']['relevant_gcse_cof_here'] = array(
    '#title' => t('Ad format on this site'),
    '#type' => 'radios',
    '#default_value' => variable_get('relevant_gcse_cof_here', 'FORID:11'),
    '#options' => array(
      'FORID:9' => t('Right'),
      'FORID:10' => t('Top and right'),
      'FORID:11' => t('Top and bottom'),
    ),
    '#description' => t('Ads on the right increase the width of the iframe. Non-profit organizations can disable ads in the Google CSE control panel.'),
  );
  $form['relevant_gcse']['relevant_gcse_cof_google'] = array(
    '#title' => t('Ad format on Google'),
    '#type' => 'radios',
    '#default_value' => variable_get('relevant_gcse_cof_google', 'FORID:0'),
    '#options' => array(
      'FORID:0' => t('Right'),
      'FORID:1' => t('Top and bottom'),
    ),
    '#description' => t('AdSense ads are also displayed when the CSE links or redirects to Google.'),
  );
  $form['relevant_gcse']['relevant_gcse_results_gadget'] = array(
    '#title' => t('Search results "Add to Google" Google Gadget'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('relevant_gcse_results_gadget', 1),
    '#description' => t('If enabled, an "Add to Google" button will be displayed above the search results.'),
  );
  $form['relevant_gcse']['relevant_gcse_results_prefix'] = array(
    '#title' => t('Search results prefix text'),
    '#type' => 'textarea',
    '#cols' => 50,
    '#rows' => 4,
    '#description' => t('Enter text to appear on the search page before the search form.'),
    '#default_value' => variable_get('relevant_gcse_results_prefix', ''),
  );
  $form['relevant_gcse']['relevant_gcse_results_suffix'] = array(
    '#title' => t('Search results suffix text'),
    '#type' => 'textarea',
    '#cols' => 50,
    '#rows' => 4,
    '#description' => t('Enter text to appear on the search page after the search form and results.'),
    '#default_value' => variable_get('relevant_gcse_results_suffix', ''),
  );
  $form['relevant_gcse']['relevant_gcse_results_searchbox_width'] = array(
    '#title' => t('Google CSE block searchbox width'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 6,
    '#description' => t('Enter the desired width, in characters, of the searchbox on the Google CSE block.'),
    '#default_value' => variable_get('relevant_gcse_results_searchbox_width', 40),
  );
  $form['relevant_gcse']['relevant_gcse_results_display'] = array(
    '#title' => t('Display search results'),
    '#type' => 'radios',
    '#default_value' => variable_get('relevant_gcse_results_display', 'here'),
    '#options' => array(
      'here' => t('On this site (requires JavaScript)'),
      'google' => t('On Google'),
    ),
    '#description' => t('Search results for the Google CSE block can be displayed on this site, using JavaScript, or on Google, which does not require JavaScript.'),
  );
  $form['relevant_gcse']['sitesearch'] = array(
    '#title' => t('SiteSearch settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['relevant_gcse']['sitesearch']['relevant_gcse_sitesearch'] = array(
    '#title' => t('SiteSearch domain'),
    '#type' => 'textarea',
    '#cols' => 50,
    '#rows' => 4,
    '#description' => t('If set, users will be presented with the option of searching only on the domain(s) specified rather than using the CSE. Enter one domain or URL path followed by a description (e.g. <em>example.com/user Search users</em>) on each line.'),
    '#default_value' => variable_get('relevant_gcse_sitesearch', ''),
  );
  $form['relevant_gcse']['sitesearch']['relevant_gcse_sitesearch_form'] = array(
    '#title' => t('SiteSearch form element'),
    '#type' => 'radios',
    '#options' => array('radios' => t('Radio buttons'), 'select' => t('Select')),
    '#description' => t('Select the type of form element used to present the SiteSearch option(s).'),
    '#default_value' => variable_get('relevant_gcse_sitesearch_form', 'radios'),
  );
  $form['relevant_gcse']['sitesearch']['relevant_gcse_sitesearch_option'] = array(
    '#title' => t('CSE search option label'),
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#size' => 60,
    '#description' => t('Customize the label for CSE search if SiteSearch is enabled (defaults to %search-web).', array('%search-web' => t('Search the web'))),
    '#default_value' => variable_get('relevant_gcse_sitesearch_option', ''),
  );
  $form['relevant_gcse']['sitesearch']['relevant_gcse_sitesearch_default'] = array(
    '#title' => t('Default to using the SiteSearch domain'),
    '#type' => 'checkbox',
    '#description' => t('If set, searches will default to using the first listed SiteSearch domain rather than the CSE.'),
    '#default_value' => variable_get('relevant_gcse_sitesearch_default', 0),
  );
  $form['relevant_gcse']['advanced'] = array(
    '#title' => t('Advanced settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_domain'] = array(
    '#title' => t('Search domain'),
    '#type' => 'textfield',
    '#maxlength' => 64,
    '#description' => t('Enter the Google domain to use for search results, e.g. <em>www.google.com</em>.'),
    '#default_value' => variable_get('relevant_gcse_domain', 'www.google.com'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_limit_domain'] = array(
    '#title' => t('Limit results to this domain'),
    '#type' => 'textfield',
    '#maxlength' => 64,
    '#description' => t('Enter the domain to limit results on
      (only display results for this domain) <em>www.google.com</em>.'),
    '#default_value' => variable_get('relevant_gcse_limit_domain', ''),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_cr'] = array(
    '#title' => t('Country restriction'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_cr', ''),
    '#description' => t('Enter a 9-letter country code, e.g. <em>countryNZ</em>, and optional boolean operators, to restrict search results to documents (not) originating in particular countries. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#crsp"><em>cr</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_gl'] = array(
    '#title' => t('Country boost'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_gl', ''),
    '#description' => t('Enter a 2-letter country code, e.g. <em>uk</em>, to boost documents written in a particular country. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#glsp"><em>gl</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_hl'] = array(
    '#title' => t('Interface language'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_hl', ''),
    '#description' => t('Enter a supported 2- or 5-character language code, e.g. <em>fr</em>, to set the language of the user interface. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#hlsp"><em>hl</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_locale_hl'] = array(
    '#title' => t('Set interface language dynamically'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('relevant_gcse_locale_hl', ''),
    '#description' => t('The language restriction can be set dynamically if the locale module is enabled. Note the locale language code must match one of the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#interfaceLanguages">supported language codes</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_ie'] = array(
    '#title' => t('Input encoding'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_ie', ''),
    '#description' => t('The default <em>utf-8</em> is recommended. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#iesp"><em>ie</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_lr'] = array(
    '#title' => t('Language restriction'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_lr', ''),
    '#description' => t('Enter a supported 7- or 10-character language code, e.g. <em>lang_en</em>, and optional boolean operators, to restrict search results to documents (not) written in particular languages. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#lrsp"><em>lr</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_locale_lr'] = array(
    '#title' => t('Set language restriction dynamically'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('relevant_gcse_locale_lr', ''),
    '#description' => t('The language restriction can be set dynamically if the locale module is enabled. Note the locale language code must match one of the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#languageCollections">supported language codes</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_oe'] = array(
    '#title' => t('Output encoding'),
    '#type' => 'textfield',
    '#default_value' => variable_get('relevant_gcse_oe', ''),
    '#description' => t('The default <em>utf-8</em> is recommended. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#oesp"><em>oe</em> parameter</a>.'),
  );
  $form['relevant_gcse']['advanced']['relevant_gcse_safe'] = array(
    '#title' => t('SafeSearch filter'),
    '#type' => 'select',
    '#options' => array('' => '', 'off' => t('Off'), 'medium' => t('Medium'), 'high' => t('High')),
    '#default_value' => variable_get('relevant_gcse_safe', ''),
    '#description' => t('SafeSearch filters search results for adult content. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#safesp"><em>safe</em> parameter</a>.'),
  );


  $form['relevant_gcse_adv'] = array(
    '#title' => t('Google CSE Advanced'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
    $form['relevant_gcse_adv']['relevant_gcse_use_adv'] = array(
    '#title' => t('Use advanced, non-adds version, search engine (You will need a pay account)'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('relevant_gcse_use_adv', 0),
    '#description' => t('If enabled, search results will be fetch using Adv engine.'),
  );

  return $form;
}
