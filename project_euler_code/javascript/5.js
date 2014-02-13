function modTest(n) {
  for (var i = 2; i <= 20; i++) {
    if (n % i) return false;
  }
  return true
}

var n = 670442572800; // MULT(11..20)

for (var i = 2; i <= 20; i++) {
  while (modTest(n/i)) {
    n /= i;
  }
}

console.log(n);
