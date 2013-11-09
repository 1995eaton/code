#!/usr/bin/python

import math

def simple_prime(num):
	z = 0
	l1 = []
	for n in range(2,round(num)):
		c = 0
		for n2 in range(2,round(num)):
			if n % n2 == 0:
				if n != n2:
					c += 1
		if c == 0:
			l1.append(n)
	return l1

def main():
	z = 0
	primes = simple_prime(math.sqrt(1000000))
	for n in range(2,1000000):
		c = 0
		for n2 in primes[:len(primes)]:
			if n % n2 == 0:
				if n != n2:
					c += 1
		if c == 0:
			print(n)
			z += n
	#print(z)

main()
