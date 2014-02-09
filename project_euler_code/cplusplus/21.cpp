#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> factors(10000, 0);
  int sum = 0;
  for (int i = 1; i < 5000; i++) {
    for (int i2 = i*2; i2 < factors.size(); i2 += i) {
      factors[i2] += i;
    }
  }
  for (int i = 0; i < factors.size(); i++) {
    if (factors[factors[i]] == i) {
      if (factors[i] == factors[factors[i]]) {
        sum -= factors[i];
      }
      sum += factors[i];
    }
  }
  cout << sum << endl;
}
