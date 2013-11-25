#!/usr/bin/python
import time
limit = 200000

ruled_out = [0] * limit * 10

def digitsSquared(n):
	chain = []
	if ruled_out[n] != 0:
		return ruled_out[n]
	while True:
		nsum = sum([int(x)**2 for x in str(n)])
		if ruled_out[n] != 0:
			for i in chain:
				ruled_out[i] = ruled_out[n]
			return ruled_out[n]
		n = nsum
		chain.append(n)
		if nsum == 89 or nsum == 1:
			for i in chain:
				ruled_out[i] = nsum
			return nsum
start_time = time.time()

count = 0
for x in range(1, limit):
	if digitsSquared(x) == 89:
		count += 1
print(count)
print(time.time() - start_time)
