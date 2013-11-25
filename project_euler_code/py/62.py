#!/usr/bin/python
import time
stime = time.time()
cubeArray = [[x, x**3, sorted(str(x**3))] for x in range(10000)]

for x in cubeArray:
	perm = [x[0]]
	for y in range(x[0], len(cubeArray)):
		if x[0] < (cubeArray[y])[0]:
			if len(x[2]) < len((cubeArray[y])[2]):
				break
			if x[2] == (cubeArray[y])[2]:
				perm.append((cubeArray[y])[0])
				if len(perm) == 5:
					print(perm)
					print(time.time() - stime)
					raise SystemExit
