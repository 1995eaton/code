var a = 0;
var b = 1;
var temp;
var sum = 0;

while (a <= 4000000) {
  temp = b;
  b = a + b;
  a = temp;
  if (!(a % 2)) sum += a;
}

console.log(sum);
