var limit = 500000;
var c = 0;
var sieve = new Array(limit+1);

for (var i = 2; i < Math.sqrt(limit); i++) {
  for (var ii = i*i; ii <= limit; ii+=i) {
    sieve[ii] = true;
  }
}

for (var i = 2; i < limit; i++) {
  if (!sieve[i]) {
    c++;
    if (c == 10000) {
      console.log(i);
      break;
    }
  }
}
