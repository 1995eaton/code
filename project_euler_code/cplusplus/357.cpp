/* g++ -Ofast -std=c++11 -march=native -Wall -c 357.cpp -o 357.o && g++ 357.o -o 357
   1739023853137 -- 19.52s user 0.01s system 99% cpu 19.540 total */

#include<iostream>
#include<cmath>
#include<vector>

using ulong = unsigned long;

int main () {

  const ulong limit = 100000000; ulong c = 0;
  std::vector<bool> primesieve (limit, 0), sieve (limit, 1);
  primesieve[2], primesieve[3] = 1;
  for (ulong x = 1; x < sqrt (limit); x++) {
    for (ulong y = 1; y < sqrt (limit); y++) {
      ulong n = 4*x*x+y*y;
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
        primesieve[n] = !primesieve[n];
      }
      n = 3*x*x+y*y;
      if (n <= limit && n % 12 == 7) {
        primesieve[n] = !primesieve[n];
      }
      n = 3*x*x-y*y;
      if (x > y && n <= limit && n % 12 == 11) {
        primesieve[n] = !primesieve[n];
      }
    }
  }
  for (ulong n = 5; n < sqrt (limit); n++) {
    if (primesieve[n]) {
      ulong nn = n*n;
      for (ulong i = nn; i < limit; i += nn) {
        primesieve[i] = 0;
      }
    }
  }
  for (ulong i = 2; i <= limit; ++i) {
    ulong ii = i;
    while (ii < limit) {
      if (!primesieve[i+ii/i]) {
        sieve[ii] = 0;
      }
      ii += i;
    }
  }
  for (ulong i = 1; i < limit; ++i) {
    if (sieve[i]) { c += i; }
  }
  std::cout << c << std::endl;
  return 0;
}
