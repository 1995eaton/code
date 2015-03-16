#include <iostream>
#include <memory>
#include <bitset>
#include <vector>
#include <cmath>

template <const uint64_t N, const uint64_t L = ((N - 1) >> 1)>
std::vector<uint64_t> primes_to() {
  std::unique_ptr<std::bitset<L>> sieve(new std::bitset<L>);
  sieve->set();

  for (uint64_t i = 0, p = 3, r = ceil(sqrt(N)); p < r; p = (++i << 1) + 3) {
    if (sieve->test(i)) {
      for (uint64_t j = (p * p - 3) >> 1; j < L; j += p) {
        sieve->reset(j);
      }
    }
  }

  std::vector<uint64_t> primes{ 2 };
  for (uint64_t i = 0; i < L; ++i) {
    if (sieve->test(i)) {
      primes.push_back((i << 1) + 3);
    }
  }

  return primes;
}

int main() {
  auto primes = primes_to<static_cast<uint64_t>(1'000'000)>();
  for (const auto& it: primes) {
    std::cout << it << std::endl;
  }
}
