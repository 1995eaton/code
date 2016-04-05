#include <stdio.h>

int main() {
  int a = 1;
  int b = 2;
  int limit = 4000000;
  int sum = 0;
  while(a < limit && b < limit) {
    printf("%d\n%d\n", a, b);
    if(a % 2 == 0) {
      sum += a;
    }
    if(b % 2 == 0) {
      sum += b;
    }
    a += b; b += a;
  }
  printf("%d\n", sum);
  return 0;
}
