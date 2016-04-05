#include <stdio.h>

int f(int n, int x) {
  int s = n / x;
  return x * (s * (s + 1) >> 1);
}

int pu1(int n) {
  return f(n, 3) + f(n, 5) - f(n, 15);
}

int main() {
  printf("%d\n", pu1(999));
}
