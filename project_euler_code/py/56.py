#!/usr/bin/python

gx = 0
for x in range(1,101):
	for y in range(1,101):
		xx = [int(x) for x in list(str(x**y))]
		sx = sum(xx)
		if gx < sx:
			gx = sx
			print(gx)
