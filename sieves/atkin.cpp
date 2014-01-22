/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Atkin for more info */

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <ctime>
#include <iomanip>

int main(int argc, char *argv[]) {

  clock_t start = std::clock();

  if(argc < 2) {
    std::cout << "Usage:\n./atkin <limit>" << std::endl;
    return 0;
  }

  unsigned long long limit;
  std::istringstream iss(argv[1]);
  iss >> limit;

  if(!limit) {
    std::cout << "Usage:\n./atkin <limit>" << std::endl;
    return 0;
  }

  std::vector<bool> sieve(limit, 0);
  sieve[2] = 1; sieve[3] = 1;

  for(unsigned long long x = 1; x < sqrt(limit); x++) {
    for(unsigned long long y = 1; y < sqrt(limit); y++) {
      unsigned long long n = 4*x*x+y*y;
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
        sieve[n] = !sieve[n];
      }
      n = 3*x*x+y*y;
      if (n <= limit && n % 12 == 7) {
        sieve[n] = !sieve[n];
      }
      n = 3*x*x-y*y;
      if (x > y && n <= limit && n % 12 == 11) {
        sieve[n] = !sieve[n];
      }
    }
  }

  for(unsigned long long n = 5; n < sqrt(limit); n++) {
    if(sieve[n]) {
      unsigned long long nn = n*n;
      for(unsigned long long i = nn; i < limit; i += nn) {
        sieve[i] = 0;
      }
    }
  }

  double sieve_fill_time = (std::clock() - start) / (double) CLOCKS_PER_SEC;

  for(unsigned long long n = 1; n <= limit; n++) {
    if(sieve[n]) {
      std::cout << n << std::endl;
    }
  }
  std::cout.width(27); std::cout << std::endl << std::left << "Completed the sieve in: " << std::right << sieve_fill_time << "s\n";
  std::cout.width(27); std::cout << std::left << "Completed the output in: " << std::right << ((std::clock() - start) / (double) CLOCKS_PER_SEC) - sieve_fill_time << "s\n";
  std::cout.width(27); std::cout << std::left << "Total time: " << std::right << (std::clock() - start) / (double) CLOCKS_PER_SEC << "s\n";
  return 0;

}
