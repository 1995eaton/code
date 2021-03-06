/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes for more info */

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
    std::cout << "Usage:\n./eratosthenes <limit>" << std::endl;
    return 0;
  }

  unsigned long long limit;
  std::istringstream iss(argv[1]);

  if (!(iss >> limit)) {
    std::cout << "Usage:\n./eratosthenes <limit>" << std::endl;
    return 0;
  }

  boost::dynamic_bitset<> sieve(limit+1);

  for (unsigned long long n = 2; n < sqrt(limit); n++) {
    for (unsigned long long i = n*n; i <= limit; i += n) {
      sieve.set(i);
    }
  }

  double sieve_fill_time = (std::clock() - start) / (double) CLOCKS_PER_SEC;

  char* output_file = strcat(argv[1], ".txt");
  std::ofstream file;
  file.open(output_file);

  for (unsigned long long n = 2; n <= limit; n++) {
    if (!sieve.test(n)) {
      file << n << std::endl;
    }
  }

  std::cout << "\e[0;32mCompleted the sieve in:\e[0;0m  " <<
    sieve_fill_time << "s\n";
  std::cout << "\e[0;32mCompleted the output in:\e[0;0m " <<
    ((std::clock() - start) / (double) CLOCKS_PER_SEC) - sieve_fill_time << "s\n";
  std::cout << "\e[0;32mTotal time:\e[0;0m              "
    << (std::clock() - start) / (double) CLOCKS_PER_SEC << "s\n";
  std::cout << "\nOutput written to " << argv[1] << std::endl;

  file.close();

  return 0;
}
