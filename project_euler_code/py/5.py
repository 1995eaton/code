#!/usr/bin/python

def main():

	n = 1
	while True:
		count = 0
		q = 2520 * n
		num = [11,13,15,16,17,19]
		for s in range(len(num)):
			if q % num[s] == 0:
				count += 1
				if count == 6:
					print(q)
					return True
		n = n + 1

main()