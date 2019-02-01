<?php
$text=$_GET["query"];
$page=$_GET["page"];
$translation=exec("java -jar TalkToMoses.jar \"".$text."\"");
$components = explode("|",$translation);
$final="";
//echo $translation;


for ($x=0; $x<=count($components); $x=$x+1){
$query = str_replace(' ', '%20', $components[$x]);
$link = "<a href=".$page."/".$query."><u>".$components[$x]."</u></a>";
$final = $final . " ". $link;
}

echo "Do you want to search for : ".$final;
?>

