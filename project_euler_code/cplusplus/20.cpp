/* g++ -lgmp -lgmpxx -std=c++11 -o 20 20.cpp */

#include <iostream>
#include <gmpxx.h>

int main() {
  mpz_class sum;
  mpz_class fact = 1;
  for (int i = 2; i <= 100; i++) {
    fact *= i;
  }
  while (fact > 0) {
    sum += fact % 10;
    fact -= fact % 10;
    fact /= 10;
  }
  std::cout << sum << std::endl;
  return 0;
}
