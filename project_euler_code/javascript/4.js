var max = 0;

for (var a = 999; a >= 100; a--) {
  for (var b = a-1; b >= 100; b--) {
    var c = String(a*b);
    if (c == c.split("").reverse().join("")) {
      if (parseInt(c) > max) {
        max = parseInt(c);
        console.log(c);
      }
    }
  }
}
