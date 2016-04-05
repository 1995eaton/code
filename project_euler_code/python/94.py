def test(a, b):
    if b % 2 != 0:
        return False
    h = a * a - b * b // 4
    z = int(h**0.5)
    if z * z != h:
        return False
    return b % 2 == 0 or z % 2 == 0

s = 0
for a in range(2, 1000000000000):
    if 3 * a + 2 > 1000000000:
        break
    if test(a, a + 1):
        print(a, a + 1, a + 1)
        s += 3 * a + 2
    if test(a + 1, a):
        print(a, a, a + 1)
        s += 3 * a + 1
print(s)
