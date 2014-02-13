var sumOfSquares = 0;
var squareOfSum = 0;

for (var i = 1; i <= 100; i++) {
  sumOfSquares += i*i;
  squareOfSum += i;
}

console.log(Math.pow(squareOfSum, 2) - sumOfSquares);
