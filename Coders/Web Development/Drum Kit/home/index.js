  document.querySelectorAll(".key")[0].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[0].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });
  document.querySelectorAll(".key")[1].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[1].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });
  document.querySelectorAll(".key")[2].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[2].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });
  document.querySelectorAll(".key")[3].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[3].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });
  document.querySelectorAll(".key")[4].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[4].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });
  document.querySelectorAll(".key")[5].addEventListener("click", function() {
    var letter = document.querySelectorAll(".key")[5].classList[0];
    letter = letter.substring(0, 1);
    playSound(letter);
    pressed(letter);
  });

  document.addEventListener("keydown", function(event) {
    playSound(event.key);
    pressed(event.key);
  });

  function playSound(key) {
    switch (key) {
      case "w":
        var audio = new Audio("resources/left-tom.mp3");
        audio.play();
        break;
      case "a":
        var audio = new Audio("resources/right-tom.mp3");
        audio.play();
        break;
      case "s":
        var audio = new Audio("resources/floor-tom.mp3");
        audio.play();
        break;
      case "d":
        var audio = new Audio("resources/bass.mp3");
        audio.play();
        break;
      case "j":
        var audio = new Audio("resources/snare.mp3");
        audio.play();
        break;
      case "k":
        var audio = new Audio("resources/crash.mp3");
        audio.play();
        break;
      default:
        console.log(key);
    }
  }

  function pressed(currentKey) {
    document.querySelector("." + currentKey).classList.add("opaque");
    document.querySelector("." + currentKey + "-icon").classList.add("opaque");
    setTimeout(function() {
      document.querySelector("." + currentKey).classList.remove("opaque");
      document.querySelector("." + currentKey + "-icon").classList.remove("opaque");
    }, 200);
  }
