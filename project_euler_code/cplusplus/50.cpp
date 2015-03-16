#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

int main() {
  clock_t start_time = clock();
  const int limit = 1000000;
  const int sqlim = round(sqrt(limit));
  int primeIter, nextPrime;
  int stringLength, recordLength;
  int cmax = 0;
  vector<bool> sieve(limit, true);
  vector<int> primes;

  for (size_t i = 2; i < sqlim; ++i) {
    size_t ii = i * 2;
    while (ii < limit) {
      sieve[ii] = false;
      ii += i;
    }
  }

  for (size_t i = 2; i < sieve.size(); ++i) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }

  for (size_t i = 0; i < primes.size() - 1; ++i) {
    primeIter = primes[i];
    nextPrime = i + 1;
    stringLength = 1;

    while (primeIter < limit) {
      if (sieve[primeIter] && stringLength > recordLength) {
        cout << primeIter << " length: " << stringLength << endl;
        recordLength = stringLength;
      }

      primeIter += primes[nextPrime];
      stringLength++;
      nextPrime++;
    }
  }

  cout << (clock() - start_time) / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
