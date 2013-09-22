#!/usr/bin/python
count = 0
l1 = []
counto = 0
for n in range(1000000,1, -1):
	count = 0
	no = n
	while n % 2 == 0:
		n = n / 2
	while n % 2 != 0:
		count += 1
		n = (3 * n) + 1
		while n % 2 == 0:
			count += 1
			n = n / 2
		if n == 1:
			count += 1
			if count > counto:
				print(no, count)
				counto = count
			break
