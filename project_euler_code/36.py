#!/usr/bin/python
def palcheck(isrange, x):
	lpal = []
	if isrange == False:
		x = str(x)
		lenx = 0
		lenxx = len(x) - 1
		if len(x) % 2 == 0:
			while lenx < len(x) / 2:
				if x[lenx] == x[lenxx]:
					lenx += 1
					lenxx -= 1
					if lenx == (len(x) / 2):
						return True
				else:
					return False
					break
		if len(x) % 2 != 0:
			while lenx <= lenxx:
				if x[lenx] == x[lenxx]:
					lenx += 1
					lenxx -= 1
					if lenx == (int(len(x) / 2) + 1):
						return True
				else:
					return False
					break
		return lpal
	if isrange == True:
		for x in range(x):
			x = str(x)
			lenx = 0
			lenxx = len(x) - 1
			if len(x) % 2 == 0:
				while lenx < len(x) / 2:
					if x[lenx] == x[lenxx]:
						lenx += 1
						lenxx -= 1
						if lenx == len(x) / 2:
							lpal.append(x)
					else:
						lpal.append(False)
						break
			if len(x) % 2 != 0:
				while lenx <= lenxx:
					if x[lenx] == x[lenxx]:
						lenx += 1
						lenxx -= 1
						if lenx == (int(len(x) / 2) + 1):
							lpal.append(x)
					else:
						lpal.append(False)
						break
		return lpal

def base2_convert(xx):
	sumyorig = 0
	for y in xx:
	#for y in (palcheck(True, 1000000)):
		l1 = []
		y = int(y)
		yorig = y
		for x in range(22,-1,-1):
			z = 2**x
			if z <= y:
				l1.append("1")
				y = y - 2**x
			else:
				if len(l1) != 0:
					l1.append("0")
		if palcheck(False, "".join(l1)) == True:
			print(yorig, "=", "".join(l1))
			sumyorig += yorig
	return sumyorig
print(base2_convert(palcheck(True, 1000000)))
