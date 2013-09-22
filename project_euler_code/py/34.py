#!/usr/bin/python

nnsum = 0
for num in range(200000):
	num = str(num)
	nsum = 0
	for n in list(num):
		na = int(n)
		nn = 1
		while na > 0:
			nn *= na
			na -= 1
		nsum += nn
		if int(num) == nsum:
			print(int(num))
			nnsum += int(num)
print(nnsum - 3)
