function erat(limit) {
  var sieve = new Array(limit+1);
  var primes = new Array;
  for (var i = 2; i < Math.sqrt(limit); i++) {
    for (var ii = i*i; ii <= limit; ii+=i) {
      sieve[ii] = true;
    }
  }
  for (var i = 2; i <= limit; i++) {
    if (!sieve[i]) {
      primes.push(i);
    }
  }
  return primes;
}

var n = 600851475143;
var primes = erat(Math.ceil(Math.sqrt(n)));

for (var i = primes.length-1; i >= 0; i--) {
  if (!(n % primes[i])) {
    console.log(primes[i]);
    break;
  }
}
