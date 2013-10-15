#!/usr/bin/python

import numpy

def Erat(limit):
	sieve = numpy.ones((limit, ), dtype=bool)
	for n in range(2, int(limit**(1/2))):
		sieve[n*2::n] = 0
	return [x for x in range(2, limit) if sieve[x] == 1]

primec = set([])
primes = Erat(10000)
limit = 50000000

for x in primes:
	if x**2> limit:
		break
	for y in primes:
		if x**2 + y**3 > limit:
			break
		for z in primes:
			if x**2 + y**3 + z**4 > limit:
				break
			primec.add(x**2 + y**3 + z**4)

count = 0
for x in sorted(primec):
	if x < limit:
		count+=1
	else:
		break

print(count)
