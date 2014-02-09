/* g++ -o 13 -std=c++11 -lgmp -lgmpxx 13.cpp */

#include <iostream>
#include <sstream>
#include <gmpxx.h>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream file("digits.txt");
  mpz_class value, temp;
  string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      temp = line;
      value += temp;
    }
  }
  cout << value << endl;
  return 0;
}
