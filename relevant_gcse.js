(function ($) {

$(function() {
  var googleCSEWatermark = function(id) {
    var f = $(id)[0];
    if (f && (f.query || f['edit-search-block-form--2'] || f['edit-keys'])) {
      var q = f.query ? f.query : (f['edit-search-block-form--2'] ? f['edit-search-block-form--2'] : f['edit-keys']);
      var n = navigator;
      var l = location;
      if (n.platform == 'Win32') {
        q.style.cssText = 'border: 1px solid #7e9db9; padding: 2px;';
      }
      var b = function() {
        if (q.value == '') {
          q.style.background = '#FFFFFF url(https://www.google.com/cse/intl/' + Drupal.settings.googleCSE.language + '/images/google_custom_search_watermark.gif) left no-repeat';
        }
      };
      var f = function() {
        q.style.background = '#ffffff';
      };
      q.onfocus = f;
      q.onblur = b;
//      if (!/[&?]query=[^&]/.test(l.search)) {
        b();
//      }
    }
  };
  googleCSEWatermark('#search-block-form.google-cse');
  googleCSEWatermark('#search-form.google-cse');
  googleCSEWatermark('#google-cse-results-searchbox-form');

  var param="";
  var sPageURL = window.location.search.substring(1);
  var wholeURL = document.URL;
  var lastIndex = wholeURL.lastIndexOf("/");
  var querypart = wholeURL.substring(lastIndex+1);
  var squerypart = querypart.split('?');
  
  if (squerypart.length != 0)
  {
	param = squerypart[0];
  }
  
/*
  var sURLVariables = sPageURL.split('&');
  for (var i = 0; i < sURLVariables.length; i++) 
  {   
      var sParameterName = sURLVariables[i].split('?');
      if (sParameterName[0] == "q") 
      {   
          param= sParameterName[1];
      }   
  }   
  */
  //var prm=param.split("/")[3];
  var prm=param;

  var pagelocation = "sites/all/modules/relevant_gcse/"
//  var pagelocation = "current/sites/all/modules/relevant_gcse"
  var page = wholeURL.substring(0, lastIndex);
  
   $("#expansion").load(pagelocation + "expansion.php?query="+prm+"&page="+page);
  
  var uri="http://qassist.cse.iitb.ac.in/facets/GetFacets?qry="+prm;
  
  $.get(pagelocation + "grabber.php?url="+uri, function( jsonstuff ) { 
    var obj=JSON.parse(jsonstuff);
    var str1="Entities : ";
    for (var i = 0; i < obj.facets.length; i++) {
    	var counter = obj.facets[i];
        str1=str1.concat("<a href=http://en.wikipedia.org/wiki/");
        str1=str1.concat(counter.displayName+" >"+counter.displayName+"</a>     ");
    }   
    
    $("#cse3").html(str1);
 }); 
});

})(jQuery);
