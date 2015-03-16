#include <iostream>
#include <vector>
#include <cmath>

int main() {
  const unsigned limit = 10000000;
  std::vector<int> numFactors(limit, 0);

  for (size_t i = 2; i < round(limit / 2); ++i) {
    unsigned int ii = i * 2;
    while (ii < limit) {
      numFactors[ii]++;
      ii += i;
    }
  }
  int c = 0;
  for (size_t i = 1; i < limit; ++i) {
    if (numFactors[i] == numFactors[i + 1]) {
      c++;
    }
  }
  std::cout << c - 1 << std::endl;
  return 0;
}
