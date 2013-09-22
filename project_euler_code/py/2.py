#!/usr/bin/python

import sys

q = 0
x = 1
z = 0

while x < 4000000:
	if q % 2 != 0:
		z += q
	q += x
	x += q
	if (x - q) % 2 != 0:
		z += (x - q)
	print(z)
