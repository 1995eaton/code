#!/usr/bin/python

import os
import time

tstart = time.time()
total = 0
popen = open("1mil.txt", "r")
plist = [int(x) for x in popen.read().split("\n")[:-1]]
#for x in range(5, len(plist) - 1):
for x in range(0, 100):
	p1 = plist[x]
	p2 = plist[x + 1]
	xx = 2
	xlen = 10**len(str(p1))
	while True:
		if (p2 * xx - p1) % xlen == 0:
			break
		xx+=1
	print(p1, p2, p2 * xx)
	total+=(p2 * xx)
print(total)
print(time.time() - tstart)
