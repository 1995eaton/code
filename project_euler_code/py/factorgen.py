from math import ceil
def factors(n):
	sieve = [[1, i] for i in range(n + 1)]
	for i in range(2, ceil(n / 2)):
		iterate = i * 2
	while iterate < n + 1:
		sieve[iterate].append(i)
	iterate += i
	del sieve[0]; del sieve[0][0]
	return sieve
