#!/usr/bin/python

def main():

	for x in range(1,26):
		#if x <= 2:
		#if x > 2 and x <= 2:
		yield x

lx = list(main())
n = 2
count = 0
y = 1
#for x in range(1,26):
l = [1]
while y < 1001 * 1001:
	if count == 4:
		n = n + 2
		count = 0
	y += n
	l.append(y)
	print(y)
	count += 1
print(sum(l))
