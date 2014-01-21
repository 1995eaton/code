
import numpy, math

def erat(limit):

 sieve = numpy.ones((limit, ), dtype=bool)
 for i in range(2, round(limit**(0.5))):
  sieve[i*2::i] = 0
 return sieve

def rad(prime, limit):

 radicals = [set([]) for i in range(limit + 1)]
 for i0, i1 in enumerate(prime):
  if i1 == 1:
   i2 = i0
   if i0 > 1:
    while i2 <= limit:
     radicals[i2].add(i0)
     i2 += i0
 radicals[1] = set([1])
 return radicals


def main(limit = 100000):

 primes = erat(limit)
 radicals = rad(primes, limit)
 rsort = []
 for i0, i1 in enumerate(radicals):
  prod = 1
  for i2 in i1:
   prod *= i2
  rsort.append([prod, i0 + 1])

 rsort = sorted(rsort)
 print(rsort[10000])

main()
