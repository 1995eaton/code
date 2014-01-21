import math
def r(n, d):
    return [d, d + n]
c = 0
z = [1, 2]
for i in range(1, 1001):
    if math.floor(math.log10(z[0] + z[1])) + 1 > math.floor(math.log10(z[1])) + 1:
        c += 1
    z = r(z[0] + z[1], z[1])
print(c)
