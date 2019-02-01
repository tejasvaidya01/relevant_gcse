<?php

/**
 * @file
 * Themeable functions for Google Custom Search Engine.
 */

/**
 * The search results page can be themed/customized.
 */
function template_preprocess_relevant_gcse_results(&$variables) {
  $query = relevant_gcse_build_query(isset($_GET['query']) ? $_GET['query'] : '', NULL, FALSE);
  $variables['results_searchbox_form'] = $variables['form'] ? drupal_get_form('relevant_gcse_results_searchbox_form') : '';
  $variables['noscript'] = t('!google, or enable JavaScript to view them here.', array('!google' => l(t('View the results at Google'), 'http://'. variable_get('relevant_gcse_domain', 'www.google.com') .'/cse', array('query' => $query))));
  $variables['prefix'] = filter_xss_admin(variable_get('relevant_gcse_results_prefix', ''));
  $variables['suffix'] = filter_xss_admin(variable_get('relevant_gcse_results_suffix', ''));

  if (relevant_gcse_validate_request()) {
    drupal_add_js($variables['path'] . '/relevant_gcse_results.js', array('scope' => 'footer'));
    //drupal_add_js('https://www.google.com/afsonline/show_afs_search.js', array('type' => 'external', 'scope' => 'footer'));
    drupal_add_js($variables['path'] . '/show_afs_search.js', array('scope' => 'footer'));
  }
}

/**
 * Display an Add-to-Google button.
 */
function template_preprocess_relevant_gcse_results_gadget(&$variables) {
  $cx = explode(':', variable_get('relevant_gcse_cx', ''));
  $variables['creator'] = rawurlencode($cx[0]);
  $variables['id'] = isset($cx[1]) ? rawurlencode($cx[1]) : '';
}

/**
 * Validate GET parameters to avoid displaying inappropriate search results.
 */
function relevant_gcse_validate_request() {
  return (
    (empty($_GET['cx']) || $_GET['cx'] == variable_get('relevant_gcse_cx', '')) &&
    (empty($_GET['safe']) || $_GET['safe'] == variable_get('relevant_gcse_safe', '')) &&
    (empty($_GET['sitesearch']) || (($options = relevant_gcse_sitesearch_options()) && isset($options[$_GET['sitesearch']])))
  );
}

/**
 * Form builder for the searchbox forms.
 */
function relevant_gcse_results_searchbox_form($form, &$form_state) {
  $form = array();
  if (variable_get('relevant_gcse_results_display', 'here') == 'here') {
    $cof = variable_get('relevant_gcse_cof_here', 'FORID:11');
  }
  else {
    $form['#action'] = 'http://'. variable_get('relevant_gcse_domain', 'www.google.com') .'/cse';
    $cof = variable_get('relevant_gcse_cof_google', 'FORID:0');
  }
  $form['#method'] = 'get';
  $form['cx'] = array(
    '#type' => 'hidden',
    '#value' => variable_get('relevant_gcse_cx', ''),
  );
  $form['cof'] = array(
    '#type' => 'hidden',
    '#value' => $cof,
  );
  $form['query'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($_GET['query']) ? $_GET['query'] : '',
  );
  $form['sa'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );
  foreach (relevant_gcse_advanced_settings() as $parameter => $setting) {
    $form[$parameter] = array(
      '#type' => 'hidden',
      '#value' => $setting,
    );
  }
  $form['query']['#size'] = intval(variable_get('relevant_gcse_results_searchbox_width', 40));
  $form['query']['#title'] = t('Enter your keywords');
  if (variable_get('relevant_gcse_results_gadget', 1)) {
    $form['sa']['#suffix'] = theme('relevant_gcse_results_gadget');
  }
  relevant_gcse_sitesearch_form($form);
  return $form;
}
