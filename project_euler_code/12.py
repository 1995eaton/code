#!/usr/bin/python

import os

x = 1
z = 1

while x < 10000000000000000000:
	count = 1
	if x % 2 == 0:
		count = 2
	for g in range(1,round(x / 2)):
		if x % g == 0:
			count += 1
			print(g)
	if count > 500:
		print("The number is", x, "\nThe number of divisors is", count)
		break
	print(x, count)
	z += 1
	x = x + z
