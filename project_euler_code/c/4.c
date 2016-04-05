#include <stdio.h>

char is_palindrone(unsigned long n) {
  unsigned long a = n;
  unsigned long b = 0;
  do {
    b = b * 10 + a % 10;
    a /= 10;
  } while (a != 0);
  return n == b;
}

unsigned long pu4(unsigned long start, unsigned long end) {
  unsigned long max = 0;
  for (unsigned long a = end; a >= start; --a) {
    if (a * 999 < max)
      break;
    for (unsigned long b = end; b >= a; --b) {
      unsigned long prod = a * b;
      if (prod < max)
        break;
      if (is_palindrone(prod)) {
        max = prod;
        break;
      }
    }
  }
  return max;
}

int main(void) {
  unsigned long start = 100;
  unsigned long end = start * 10 - 1;
  printf("%lu\n", pu4(start, end));
}
