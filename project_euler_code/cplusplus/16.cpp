/* g++ -lgmp -lgmpxx -std=c++11 -o 16 16.cpp */

#include <iostream>
#include <sstream>
#include <vector>
#include <gmpxx.h>

using namespace std;

int main() {
  mpz_class prod = 2;
  mpz_class d = 0;
  for (int i = 0; i < 999; i++) {
    prod *= 2;
  }
  while (prod > 0) {
    d += prod % 10;
    prod -= prod % 10;
    prod /= 10;
  }
  cout << d << endl;
  return 0;
}
