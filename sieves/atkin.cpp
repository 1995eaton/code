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

  if (argc < 2) {
    std::cout << "Usage:\natkin <limit>" << std::endl;
    return 0;
  }

  clock_t start = std::clock();
  uint64_t limit, x, y, n, i, j, q, sq;
  double sieve_fill_time;

  std::ofstream file(strcat(argv[1], ".txt"), std::ofstream::binary);
  std::stringstream prime_str(std::stringstream::out|std::stringstream::binary);
  std::istringstream iss(argv[1]);

  if (!(iss >> limit)) {
    std::cout << "Usage:\natkin <limit>" << std::endl;
    return 0;
  }

  if (limit < 3) {
    return 0;
  }

  sq = sqrt(limit);
  boost::dynamic_bitset<> sieve(limit + 1);
  sieve.set(2); sieve.set(3);

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

  for (i = 5; i < sq; i++) {
    if (sieve.test(i)) {
      for (j = q = i * i; j < limit; j += q) {
        sieve.reset(j);
      }
    }
  }

  sieve_fill_time = (std::clock() - start) / (double) CLOCKS_PER_SEC;

  for (i = 1; i < limit; i += 2) {
    if (sieve.test(i)) {
      prime_str << i << "\n";
    }
  }
  file.write(prime_str.str().c_str(), prime_str.str().length());

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
