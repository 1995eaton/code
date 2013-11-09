#!/usr/bin/python

for a in range(1,1001):
		for b in range(1,1001):
			if a < b:
				for c in range(1,1001):
					if c > b:
						if a + b + c == 1000:
							if (a * a) + (b * b) == (c * c):
								print(a,b,c)
