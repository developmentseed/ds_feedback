<?php

/**
 * Feedback box type.
 */
class ds_feedback_box extends boxes_simple {


  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $defaults = parent::options_defaults();
    $defaults['button_title'] = t('Send feedback');
    return $defaults;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    $form = parent::options_form();
    $form['button_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Button title'),
      '#default_value' => $this->options['button_title'],
      '#description' => t('The text to be used for the contact button.'),
    );
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    drupal_add_css(drupal_get_path('module', 'ds_feedback') . '/ds_feedback.css');
    drupal_add_js(drupal_get_path('module', 'ds_feedback') . '/ds_feedback.js');

    $query = array(
      'subject' => t('Feedback'),
      'content' => t('Page: !url', array('!url' => url($_GET['q'], array('absolute' => TRUE)))) ."\n\n",
    );

    $block = parent::render();
    $block['content'] .= "<div class='buttons'>";
    $block['content'] .= l($this->options['button_title'], 'contact', array('query' => $query, 'attributes' => array('class' => array('button'))));
    $block['content'] .= "</div>";
    return $block;
  }

}