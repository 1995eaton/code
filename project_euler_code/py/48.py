#!/usr/bin/python

nsum = 0
ncount = 0
for n in range(1,1001):
	ncount += 1
	n = n**ncount
	print(str(nsum)[len(str(nsum)) - 10:])
	nsum += n
	#print(str(nsum))
