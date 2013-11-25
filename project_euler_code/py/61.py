#!/usr/bin/python
import itertools

def lf(n0, n1):
	if n0 % 100 == int(str(n1)[0:2]):
		return 1
	return 0

def CyclicCheck(l0, l1, l2, l3, l4, l5):
	for x0 in l0:
		for x1 in l1:
			if lf(x0, x1) == 1:
				for x2 in l2:
					if lf(x1, x2) == 1:
						for x3 in l3:
							if lf(x2, x3) == 1:
								for x4 in l4:
									if lf(x3, x4) == 1:
										for x5 in l5:
											if lf(x4, x5) == 1 and lf(x5, x0) == 1:
												if x0 != 1:
													print(x0, x1, x2, x3, x4, x5, x0+x1+x2+x3+x4+x5)
													return 0

def main(limit = 1000):
	triangle = [int(n*(n + 1)/2) for n in range(45, 141)]
	square = [int(n**2) for n in range(32, 100)]
	pentagonal = [int(n*(3*n-1)/2) for n in range(26, 82)]
	hexagonal = [n*(2*n-1) for n in range(23, 71)]
	heptagonal = [int(n*(5*n-3)/2) for n in range(21, 64)]
	octagonal = [n*(3*n-2) for n in range(19, 59)]

	for x in list(itertools.permutations([octagonal, heptagonal, hexagonal, pentagonal, square, triangle], 6)):
		if CyclicCheck(x[0], x[1], x[2], x[3], x[4], x[5]) == 0:
			break
main()
