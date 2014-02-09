/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Atkin for more info */

#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

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

  char* output_file = strcat(argv[1], ".txt");
  std::ofstream file;
  file.open(output_file);

  for (unsigned long long n = 1; n < limit; n++) {
    if (sieve.test(n)) {
      file << n << std::endl;
    }
  }

  std::cout << "\e[0;32mCompleted the sieve in:\e[0;0m  "
    << sieve_fill_time << "s\n";
  std::cout << "\e[0;32mCompleted the output in:\e[0;0m "
    << ((std::clock() - start) / (double) CLOCKS_PER_SEC) - sieve_fill_time << "s\n";
  std::cout << "\e[0;32mTotal time:\e[0;0m              "
    << (std::clock() - start) / (double) CLOCKS_PER_SEC << "s\n";
  std::cout << "\nOutput written to " << argv[1] << std::endl;

  file.close();
  return 0;

}
