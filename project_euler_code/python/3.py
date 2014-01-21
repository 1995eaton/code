import numpy, math

def Erat(lim):
 sieve = numpy.ones((lim, ), dtype = numpy.bool)
 for i in range(2, int(lim**0.5)):
  sieve[i*2::i] = False
 return [index for index, i in enumerate(sieve) if i == True][2:]

def main(n = 600851475143):
 primes = Erat(int(n**0.5))[::-1]
 for i in primes:
  if not n % i:
   print(i)
   break

main()
