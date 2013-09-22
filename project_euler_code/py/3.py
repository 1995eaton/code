#!/usr/bin/python

#ptest checks a number's factors for primes - does not use seive's method

def ptest(num):
	for a in range(1, num + 1):
		if num % a == 0:
			count = 0
			for p in range(1,a + 1):
				if a % p == 0:
					count+= 1
			if count == 2:
				print(a, "is prime.")

i = input("Enter a number: ")
ptest(int(i))
