function isPrime(n) {
  if (n <= 1)
    return false;
  var s = Math.floor(Math.sqrt(n)) + 1;
  for (var i = 2; i < s; i++)
    if (n % i === 0)
      return false;
  return true;
}

function isLeftTruncatable(n) {
  var r = 0, p = 1;
  while (n > 0) {
    r += p * (n % 10);
    p *= 10;
    if (!isPrime(r))
      return false;
    n = Math.floor(n / 10);
  }
  return true;
}

function pe37() {
  var trunc = [];
  function recurse(left) {
    left *= 10;
    [1, 3, 7, 9].forEach(function(n) {
      var p = left + n;
      if (isPrime(p)) {
        recurse(p);
        if ((n === 3 || n === 7) && isLeftTruncatable(p))
          trunc.push(p);
      }
    });
  }
  [2, 3, 5, 7].forEach(recurse);
  return trunc.reduce(function(a, b) { return a + b; });
}

var startTime = Date.now();
console.log(pe37());
console.log('finished in ' + (Date.now() - startTime) / 1000 + 's');
