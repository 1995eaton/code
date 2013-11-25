#!/usr/bin/python
import math, numpy

limit = 1000

def erat(n):
	sieve = numpy.ones((n,), dtype=bool)
	for x in range(2, round(math.sqrt(n))):
		sieve[x*2::x] = 0
	return [x for x in range(2,n) if sieve[x] == True]

def main(limit = 150000):
	primes = erat(1000)
	factors = [0 for x in range(0, limit + 1)]
	for x in primes:
		xx = x
		while xx < limit:
			factors[xx]+=1
			xx += x
	for x in range(0, len(factors)):
		c=0
		while factors[x] == 4:
			c+=1
			if c==4:
				print(x-3, x-2, x-1, x)
				return 0
			x+=1
main()
