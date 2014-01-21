import numpy, math
def Erat(lim):
 sieve = numpy.ones((lim, ), dtype=numpy.bool)
 for i in range(2, int(lim**0.5)):
  sieve[i*2::i] = 0
 return [index + 2 for index, i in enumerate(sieve[2:]) if i]
def main(lim = 1000000, l = 1, c = 0):
 primes = Erat(lim)
 for p in primes:
  for n in [i**3 for i in range(l, 600)]:
   if round((n + p)**(1.0/3))**3 == n + p:
    l = int(n**(1.0/3))
    c += 1
    print c, p

main()
