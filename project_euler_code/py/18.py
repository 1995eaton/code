#!/usr/bin/python

def main():
	z = 0
	z1=0
	a1 = 3
	a2 = 3
	aa1 = 0
	aa2 = 0
	g1 = [3], [7, 4], [2, 4, 6], [8, 5, 9, 3]
	for x in range(len(g1) - 1):
		n = 0
		for y in g1[x]:
			n+=1
			for z in range(len(g1[x + 1]) - 1):
				a1 += g1[x + 1][n - 1]
				a2 += g1[x + 1][n]
				print(a1)
				#print(a2)
				aa1 += a1
				aa2 += a2
				#print(aa1)
				#print(aa2)
				break

main()
