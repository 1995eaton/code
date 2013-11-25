#!/usr/bin/python

limit = 55385

l1 = set([])
l2 = set([])

for x in range(2, limit + 1):

	l1.add(int(x * (x + 1) / 2))

for x in range(2, limit + 1):

	pent = int(x * (3 * x - 1) / 2)
	if pent in l1:
		l2.add(pent)

for x in range(2, limit + 1):

	hexa = int(x * (2 * x - 1))
	if hexa in l2:
		print(hexa)
