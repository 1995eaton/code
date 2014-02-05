/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Atkin for more info */

#include <iostream>
#include <cmath>
#include <boost/dynamic_bitset.hpp>
#include <sstream>
#include <ctime>

int main(int argc, char *argv[]) {

  clock_t start = std::clock();

  if (argc < 2) {
    std::cout << "Usage:\natkin <limit>" << std::endl;
    return 0;
  }

  unsigned long long limit;

  std::istringstream iss(argv[1]);
  if (!(iss >> limit)) {
    std::cout << "Usage:\natkin <limit>" << std::endl;
    return 0;
  }
  boost::dynamic_bitset<> sieve(limit+1);
  sieve.set(2); sieve.set(3);

  for (unsigned long long x = 1; x < sqrt(limit); x++) {
    for (unsigned long long y = 1; y < sqrt(limit); y++) {
      unsigned long long n = 4*x*x+y*y;
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
        sieve.flip(n);
      }
      n = 3*x*x+y*y;
      if (n <= limit && n % 12 == 7) {
        sieve.flip(n);
      }
      n = 3*x*x-y*y;
      if (x > y && n <= limit && n % 12 == 11) {
        sieve.flip(n);
      }
    }
  }

  for (unsigned long long n = 5; n < sqrt(limit); n++) {
    if (sieve.test(n)) {
      for (unsigned long long i = n*n; i < limit; i += n) {
        sieve.reset(i);
      }
    }
  }

  double sieve_fill_time = (std::clock() - start) / (double) CLOCKS_PER_SEC;

  for (unsigned long long n = 1; n < limit; n++) {
    if (sieve.test(n)) {
      std::cout << n << std::endl;
    }
  }
  std::cout.width(27); std::cout << std::endl << std::left <<
    "Completed the sieve in: " << std::right << sieve_fill_time << "s\n";
  std::cout.width(27); std::cout << std::left << "Completed the output in: " <<
    std::right << ((std::clock() - start) / (double) CLOCKS_PER_SEC) - sieve_fill_time << "s\n";
  std::cout.width(27); std::cout << std::left << "Total time: " <<
    std::right << (std::clock() - start) / (double) CLOCKS_PER_SEC << "s\n";
  return 0;

}
