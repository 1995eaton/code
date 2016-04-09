#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static bool is_prime(int n) {
    if (n <= 2)
        return n == 2;
    int s = sqrt(n) + 1;
    for (int i = 3; i < s; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

static bool is_left_truncatable(int n) {
    int r = 0, p = 1;
    while (n > 0) {
        r += p * (n % 10);
        if (!is_prime(r))
            return false;
        p *= 10;
        n /= 10;
    }
    return true;
}

static inline int recurse(int left) {
    left *= 10;
    int s = 0;
    for (int i = 0; i < 4; i++) {
        int n = 3 * i + ((i & 1) ^ 1);
        int p = left + n;
        if (is_prime(p)) {
            s += recurse(p);
            if ((n == 3 || n == 7) && is_left_truncatable(p))
                s += p;
        }
    }
    return s;
}

static int pe37() {
    return recurse(2) + recurse(3) + recurse(5) + recurse(7);
}

int main(void) {
    printf("%d\n", pe37());
}
