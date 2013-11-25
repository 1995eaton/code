import numpy

def main(lim):
 sieve = numpy.ones((lim, ), dtype = numpy.bool)
 for i in range(2, int(lim**0.5)):
  sieve[i**2::i] = False
 return sum([index for index, i in enumerate(sieve[2:]) if i == True and index < 2000000])

print(main(2100000))
