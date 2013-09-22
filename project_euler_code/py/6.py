#!/usr/bin/python

import math

a, b = 0, 0

for n in range(1,101):
	c = n * n
	a += c
	b += n
print((b * b) - a)
