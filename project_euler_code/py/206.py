#!/usr/bin/python
import math

digits = '1234567890'

for i in range (1389100000, 1000000000, -10):
	ii = str(i**2)
	if ii[::2] == digits:
		print(i**2)
		break

