/* Compile with g++ -Ofast -march=native for best results
   See http://en.wikipedia.org/wiki/Sieve_of_Sundaram for more info */

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
    std::cout << "Usage:\nsundaram <limit>" << std::endl;
    return 0;
  }

  unsigned long long limit;

  std::istringstream iss(argv[1]);
  if (!(iss >> limit)) {
    std::cout << "Usage:\nsundaram <limit>" << std::endl;
    return 0;
  }

  limit = (int) limit/2;
  boost::dynamic_bitset<> sieve(limit+1);

  for (unsigned long long i = 1; i <= limit; i++) {
    for (unsigned long long j = 1; j <= (limit-i)/((i<<1)+1); j++) {
      sieve.set(i+j+2*i*j);
    }
  }

  double sieve_fill_time = (std::clock() - start) / (double) CLOCKS_PER_SEC;

  char* output_file = strcat(argv[1], ".txt");
  std::ofstream file;
  file.open(output_file);

  file << 2 << std::endl;
  for (unsigned long long n = 1; n <= limit; n++) {
    if (!sieve.test(n)) {
      file << n*2+1 << std::endl;
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
