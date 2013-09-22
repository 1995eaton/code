#!/usr/bin/python

x = float(1/2)
count = 0
n = 1
s = 0
count1 = 0
while True:
	xx = 1 + x
	n = (n * 2) + s
	print(n)
	s += n
	x = (1 / (2 + x))
	count += 1
	if count == 5:
		break
