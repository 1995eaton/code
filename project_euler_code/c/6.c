#include <stdio.h>
#include <stdlib.h>

int main() {

  int sumOfSquares = 0;
  int squareOfSum = 0;
  for (int i = 1; i <= 100; i++) {
    sumOfSquares += i*i;
    squareOfSum += i;
  }
  squareOfSum *= squareOfSum;
  printf("%d - %d = %d\n", sumOfSquares, squareOfSum, abs(sumOfSquares-squareOfSum));
  return 0;

}
