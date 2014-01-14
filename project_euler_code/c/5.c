#include <stdio.h>
#include <stdbool.h>

bool modTest(unsigned long n) {

  for (int i = 2; i <= 20; i++) {
    if (n % i) {
      return false;
    }
  }
  return true;
}

int main() {

  unsigned long n = 670442572800; // for n in (11..20) -> ∏ n
  for (int i = 2; i <= 20; i++) {
    while (modTest(n/i)) {
      n /= i;
    }
  }
  printf("%lu\n", n);

  return 0;
}
