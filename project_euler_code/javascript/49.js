function getPrimes() {
  var sieve = new Int8Array(10001),
      primes = [];
  for (var x = 1; x < 100; x++) {
    for (var y = 1; y < 100; y++) {
      var n = 4*x*x + y*y;
      if (n <= 10000 && (n % 12 === 1 || n % 12 === 5)) {
        sieve[n] ^= 1;
      }
      n = 3*x*x + y*y;
      if (n <= 10000 && n % 12 === 7) {
        sieve[n] ^= 1;
      }
      n = 3*x*x - y*y;
      if (x > y && n <= 10000 && n % 12 === 11) {
        sieve[n] ^= 1;
      }
    }
  }
  for (var i = 5; i < 100; i++) {
    if (sieve.get(i)) {
      for (var q = i * i, j = q; j < 10000; j += q) {
        sieve[j] = 0;
      }
    }
  }
  for (i = 1001; i < 10000; i += 2) {
    if (sieve.get(i)) {
      primes.push(i);
    }
  }
  return {
    primes: primes,
    sieve: sieve
  };
}

function isPermutation(i, j) {
  var iDigits = [];
  while (i > 0) {
    iDigits.push(i % 10);
    i = ~~(i / 10);
  }
  while (j > 0) {
    var idex = iDigits.indexOf(j % 10);
    if (idex === -1) {
      return false;
    }
    iDigits[idex] = -1;
    j = ~~(j / 10);
  }
  return true;
}

var primeInfo = getPrimes(),
    primes = primeInfo.primes,
    plength = primes.length,
    sieve = primeInfo.sieve;

(function() {
  for (var i = 0; i < plength; i++) {
    if (primes[i] !== 1487) {
      for (var j = i + 1, k; (k = (primes[j] << 1) - primes[i]) < 10000; j++) {
        if (sieve[k] && isPermutation(primes[i], primes[j]) && isPermutation(primes[j], k)) {
          return console.log('%d%d%d', primes[i], primes[j], k);
        }
      }
    }
  }
})();
