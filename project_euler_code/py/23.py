#!/usr/bin/python

abun = set()

for x in range(1,100):
	divcount = 0
	for y in range(1,int(x**0.5) + 1):
		if x % y == 0:
			#print(x//y, y, x, sep="\t")
			if y != x//y:
				divcount += x//y + y
			else:
				divcount += y
	if (divcount - x) > x:
		#print(x, divcount - x)
		#print(x, divcount - x)
		abun.add(x)
print(sorted(abun))
#nonabun = set([x for x in range(1,1000)])
#for x in range(1,1000):
	#for y in abun:
		#if y <= x:
			##print(y, x//y)
			#if x - y in abun or x - y == 0:
				#nonabun.discard(x)
##for xx in range(1,24):
	##nonabun.add(xx)
##for x in abun:
	##if x % 2 != 0:
		##print(x)
##print(abun)
#print(nonabun)
#print(sum(nonabun))
