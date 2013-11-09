#!/usr/bin/python
import math

digitFactorials = []
for x in range(0, 10):
	digitFactorials.append(math.factorial(x))

def main(loopLength, limit, c = 0):
	for n in range(1, limit):
		loopArray = set([])
		loopSize = 0
		nn = n
		count = 0
		while sum([digitFactorials[int(x)] for x in str(n)]) != nn:
			loopArray.add(n)
			n = sum([digitFactorials[int(x)] for x in str(n)])
			if len(loopArray) == loopSize:
				count += 1
			else:
				count = 0
			if count == 1:
				break
			loopSize = len(loopArray)
		if len(loopArray) == loopLength:
			print(nn)
			c += 1
	return c

print(main(60, 1000000))
