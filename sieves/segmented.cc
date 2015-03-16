#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include <cmath>

template <const size_t N, const size_t L = N / 8 + 1>
class bitset {
  private:
    char bytes[L];

  public:
    bitset() = default;

    template<typename T>
    bitset(bool initial_value) {
      if (initial_value) {
        set();
      } else {
        reset();
      }
    }

    void set() {
      std::fill(bytes, bytes + L, 0xff);
    }

    void set(size_t index) {
      bytes[index / 8] |= 1 << (index & 7);
    }

    void reset() {
      std::fill(bytes, bytes + L, 0);
    }

    void reset(size_t index) {
      bytes[index / 8] &= ~(1 << (index & 7));
    }

    bool test(size_t index) {
      return !!(bytes[index / 8] & (1 << (index & 7)));
    }
};

template <const uint64_t N, const uint64_t L = ((N - 1) >> 1)>
void primes_to(std::function<void(uint64_t)> callback) {
  std::unique_ptr<bitset<L>> sieve(new bitset<L>);
  sieve->set();
  for (uint64_t i = 0, p = 3, r = ceil(sqrt(N)); p < r; p = (++i << 1) + 3) {
    if (sieve->test(i)) {
      for (uint64_t j = (p * p - 3) >> 1; j < L; j += p) {
        sieve->reset(j);
      }
    }
  }
  callback(2);
  for (uint64_t i = 0; i < L; ++i) {
    if (sieve->test(i)) {
      callback((i << 1) + 3);
    }
  }
}

int main() {
  size_t i = 0;
  primes_to<static_cast<uint64_t>(1'000'000'000)>([&](uint64_t prime) {
    std::cout << ++i << ' ' << prime << std::endl;
  });
}
