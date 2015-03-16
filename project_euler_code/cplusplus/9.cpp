#include <iostream>
#include <cmath>

#define LIMIT 500

int main() {

  int a, b;
  float c;

  for (a = 1; a < LIMIT; a++) {
    for (b = a + 1; b < LIMIT; b++) {
      c = sqrt(a*a + b*b);
      if (a + b + c == 1000) {
        std::cout << int(a * b * c) << std::endl;
        return 0;
      }
    }
  }

  return 0;

}
