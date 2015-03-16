/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Atkin for more info */

#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>

const uint64_t limit = 1'000'000'000;
const uint64_t sq = sqrt(limit);

int main() {

  clock_t start = std::clock();
  uint64_t x, y, n, q;


  std::bitset<limit+1>& sieve = *(new std::bitset<limit+1>());
  sieve.set(2);
  sieve.set(3);

  for (x = 1; x < sq; x++) {
    for (y = 1; y < sq; y++) {
      n = 4*x*x + y*y;
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
        sieve.flip(n);
      }
      n = 3*x*x + y*y;
      if (n <= limit && n % 12 == 7) {
        sieve.flip(n);
      }
      n = 3*x*x - y*y;
      if (x > y && n <= limit && n % 12 == 11) {
        sieve.flip(n);
      }
    }
  }

  for (x = 5; x < sq; x++) {
    if (sieve.test(x)) {
      q = x * x;
      for (y = q; y < limit; y += q) {
        sieve.reset(y);
      }
    }
  }

  std::cout << (std::clock() - start) / (double) CLOCKS_PER_SEC  << "s\n";

  return 0;

}
