#!/usr/bin/python
for n in range(1000000):
	if sorted(list(str(n))) == sorted(list(str(n*2))):
		if sorted(list(str(n))) == sorted(list(str(n*3))):
			if sorted(list(str(n))) == sorted(list(str(n*4))):
				if sorted(list(str(n))) == sorted(list(str(n*5))):
					if sorted(list(str(n))) == sorted(list(str(n*6))):
						print(n)
