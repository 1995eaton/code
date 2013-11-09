#!/usr/bin/python

xx = []
x = 0
while True:
	xy = list(str(x))
	for a in xy:
		xx.append(a)
	x += 1
	if len(xx) >= 1500000:
		break
n = 1
count = 0
z = 1
while True:
	z *= int(xx[n])
	n *= 10
	count += 1
	if count == 7:
		break
print(z)
