# https://en.wikipedia.org/wiki/Chakravala_method

def chakravala(n):
    if int(n**0.5)**2 == n:
        return None
    a, b, k, m = 1, 0, 1, 1

    while True:
        m = 2 * k + k * int(m / k) - m
        m -= int((m - n**0.5) / k) * k

        _a = a
        a = (a * m + n * b) // abs(k)
        b = (_a + b * m) // abs(k)
        k = (m * m - n) // k
        if k == 1:
            break
    return a

if __name__ == '__main__':
    m, z = 0, 0
    for i in range(2, 1001):
        r = chakravala(i)
        if r != None and r > m:
            m, z = r, i
    print(z)
