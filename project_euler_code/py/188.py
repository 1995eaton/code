def Mexp(b, e, m, r = 1):
 while e > 0:
  if e % 2 == 1:
   r = (r * b) % m
  e, b = e >> 1, b**2 % m
 return r
def main(n = 1855):
 for i in range(1855, 0, -1):
  n = Mexp(1777, n, 10**8)
 return n

print(main())
