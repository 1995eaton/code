/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Atkin for more info */

// sum of first billion: 11138479445180240497
// billionth prime:               22801763489

#include <cmath>
#include <bitset>
#include <iostream>

const uint64_t LIMIT = 24000000000;
const uint64_t SQRT = sqrt(LIMIT);

int main() {

  uint64_t x, y, n, i, j, q;
  uint64_t sum = 0;
  uint64_t pcount = 0;

  std::bitset<LIMIT + 1>& sieve = *(new std::bitset<LIMIT + 1>());
  sieve.set(2); sieve.set(3);

  for (x = 1; x < SQRT; x++) {
    for (y = 1; y < SQRT; y++) {
      n = 4*x*x + y*y;
      if (n <= LIMIT && (n % 12 == 1 || n % 12 == 5)) {
        sieve.flip(n);
      }
      n = 3*x*x + y*y;
      if (n <= LIMIT && n % 12 == 7) {
        sieve.flip(n);
      }
      n = 3*x*x - y*y;
      if (x > y && n <= LIMIT && n % 12 == 11) {
        sieve.flip(n);
      }
    }
  }

  for (i = 5; i < SQRT; i++) {
    if (sieve.test(i)) {
      for (j = q = i * i; j < LIMIT; j += q) {
        sieve.reset(j);
      }
    }
  }

  for (i = 2; i < LIMIT; i++) {
    if (sieve.test(i)) {
      pcount++;
      sum += i;
      if (pcount == 1000000000) {
        std::cout << "Sum of first billion: " << sum << std::endl;
        std::cout << "Billionth prime number: " << i << std::endl;
      }
    }
  }
  std::cout << pcount << std::endl << sum << std::endl;
  return 0;

}
