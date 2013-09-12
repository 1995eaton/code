#!/usr/bin/python

x = list(str(2**1000))
z = 0
for y in range(len(x)):
	z += int(x[y])
print(z)
