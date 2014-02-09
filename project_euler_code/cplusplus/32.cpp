#include <iostream>
#include <set>

int digit_count(int n) {
  int p = 0;
  while (n > 0) {
    p++;
    n -= n%10;
    n /= 10;
  }
  return p;
}

void dparse(int n, std::set<int> &digits) {
  while (n > 0) {
    if (n%10 != 0) {
      digits.insert(n%10);
    }
    n -= n%10;
    n /= 10;
  }
}

int main() {
  int dc, c;
  int sum = 0;
  std::set<int> digits, prod;
  std::set<int>::iterator it;
  for (int a = 2; a < 5000; a++) {
    for (int b = 2; b < 5000; b++) {
      c = a*b;
      dc = digit_count(a) + digit_count(b) + digit_count(c);
      if (dc > 9) {
        break;
      }
      if (dc == 9) {
        dparse(a, digits);
        dparse(b, digits);
        dparse(c, digits);
        if (digits.size() == 9) {
          prod.insert(c);
        }
        digits.clear();
      }
    }
  }
  for (it = prod.begin(); it != prod.end(); ++it) {
    sum += *it;
  }
  std::cout << sum << std::endl;
  return 0;
}
