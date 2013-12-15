
import numpy, math, itertools

def erat(limit):
 sieve = numpy.ones((limit, ), dtype=bool)
 for i in range(2, math.floor(limit**(0.5))):
  sieve[i*2::i] = 0
 return [i for i in range(2, limit) if sieve[i] == 1]

limit = 10**8
c = 0
limit2 = int((limit / 2) + 1000)
primes = erat(limit2)
for i0, i1 in enumerate(primes):
 i0_ = i0
 while primes[i0_] < limit / i1:
  c+=1
  print(i1, primes[i0_])
  i0_+=1
print(c)
