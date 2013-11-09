#!/usr/bin/python
limit = int(input("Limit: "))
l1 = [list(str(x)) for x in range(limit)]
xsum = 0
for x in l1:
	x3 = 0
	for x2 in range(len(x)):
		#xsum += int(x[x2 - 1])
		xnum = int("".join(x))
		x2 = int(x[x2 - 1])**5
		if x3 > xnum:
			break
		x3 += x2
	if xnum == x3:
		xsum += xnum
		print(xnum, xsum - 1)

