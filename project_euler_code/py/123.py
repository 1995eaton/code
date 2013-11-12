import numpy
def Erat(lim):
 sieve = numpy.ones((lim, ), dtype=numpy.bool)
 for i in range(2, int(lim**0.5)):
  sieve[i*2::i] = False
 return sieve[2:]
def main(n = 0):
 for index, i in enumerate(Erat(1000000)):
  if i == 1 and index % 2 != 0:
   n += 1
   if 2*n*(index + 2) > 10000000000:
    return n + 2
print(main())
