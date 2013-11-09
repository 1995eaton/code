#!/usr/bin/python

ss = set(['1', '2', '3', '4', '5', '6', '7', '8', '9'])
resset = set([])

for a in range(1,10000):
	for b in range(1,10000):
		s = str(a) + str(b) + str(a*b)
		sset = set(s)
		if len(s) == 9 and sset == ss:
			print(a, b, a * b)
			resset.add(a*b)
			print(sum(resset))
