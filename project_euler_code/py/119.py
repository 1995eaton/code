#!/usr/bin/python

import time

start_time = time.time()
digitSums = [[] for x in range(100)]
results = []

for i0 in range(2, 100):
	for i1 in range(2, 9):
		digitSums[i0].append(i0**i1)

for index, i0 in enumerate(digitSums):
	for i1 in i0:
		digit_sum = 0
		for i2 in str(i1):
			digit_sum += int(i2)
		if digit_sum == index:
			results.append(i1)

for index, i0 in enumerate(sorted(results)[:30]):
	print(index + 1, i0)

print(time.time() - start_time)
