#!/usr/bin/python
import os
count2 = 0
q1 = input("Which prime do you want?")
n = 0
while True:
	n = n + 1
	if n % 2 != 0:
		count = 0
		for n2 in range(1, round(n / 2)):
			if n % n2 == 0:
				count += 1
		if count == 1:
			count2 += 1
			os.system("clear")
			print(count2)
			if count2 == int(q1) - 1:
				os.system("clear")
				print(n)
				break
