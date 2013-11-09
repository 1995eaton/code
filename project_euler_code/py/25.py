#!/usr/bin/python

x, y = 1, 0
count = 0
while True:
	x, y = y, x + y
	#print(count, len(str(x)), x)
	if x != 0 and len(str(x)) == 1000:
		print(count, len(str(x)), x)
		break
	count += 1
