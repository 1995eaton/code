#!/usr/bin/python

l1 = []
l2 = []

def main():
	for x in range(100,1000):
		for y in range(100,1000):
			l1.append(x * y)
	for z in range(0,len(l1)):
		if len(str(l1[z])) == 6:
			p = str(l1[z])
			if p[0] == p[5]:
				if p[1] == p[4]:
					if p[2] == p[3]:
						l2.append(l1[z])
	print(sorted(l2))

main()
