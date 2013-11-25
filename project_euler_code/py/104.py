#!/usr/bin/python

def main(a = 1, b = 0, c = 0):
	while True:
		if len(set(str(a%10**9))) == 9 and '0' not in set(str((a%10**9))):
			if "".join(sorted(str(a)[0:9])) == "123456789":
				print('\n', c+1, sep='')
				raise SystemExit
			print(c+1)
		c+=1
		a, b = a + b, a

main()
