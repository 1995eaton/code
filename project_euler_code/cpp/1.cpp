#include<iostream>

int main() {
  int s = 0;
  for (int i = 0; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) { s += i; }
  }
  std::cout << s << std::endl;
  return 0;
}
