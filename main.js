var newFont = "Comic Sans MS"; //input your font here
var e = document.querySelectorAll('h1, h2, h3, h4, h5, h6, p, span, div, a, li, td, th');
e.forEach(function(t){t.style.fontFamily = newFont;});
