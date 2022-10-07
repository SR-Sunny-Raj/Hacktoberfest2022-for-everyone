<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Messaging APP</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>    
<div class="center"> 
<form action="" method="POST">
    <br><br>
<p>"You could say things with colour and shapes that you could not say any other way - things you do not have words for."</p>
<br>
   <h1 style="color:white;font-style:italic;font-family:lucida">Leave Us With A Comment :)</h1>
   <label> Name: 
    <input type="text" name="Name" class="Input"style="border: radius 10px;" style="width: 225px" placeholder='Ex : Sung-JinWoo' required>
   </label>
   <br><br>
   <label> Comment: <br>
   <br>
    <textarea name="Comment" style="border: radius 10px;"class="Input" style="width: 300px" placeholder='Shower with quote 'required ></textarea>
   </label>
   <br><br>
   <input type="submit" name="Submit" value="Submit" class="Submit" style="border: radius 10px;">
   <br><br>
  </form>
    </div>

</body>
</html>
<?php
 
 if($_POST['Submit']){

  $Name = $_POST['Name'];
  $Comment = $_POST['Comment'];

  $old = fopen("comments.txt", "r+t");
  $old_comments = fread($old, 1024);

  $write = fopen("comments.txt", "w+");//mainly for appending comments in igniter website
  $string = "<b><h2>".$Name."</b><br><h4>".$Comment."<br>".$old_comments;
  fwrite($write, $string);
  fclose($write);
  fclose($old);
 }

 $read = fopen("comments.txt", "r+t");//reading old comments
 echo "<br><br>Comments<hr>".fread($read, 1024);
 fclose($read);

?>

