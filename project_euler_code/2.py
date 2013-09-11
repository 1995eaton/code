#!/usr/bin/python

import sys

q = 0
x = 1
z = 0

while x < 4000000:
	if q % 2 != 0:
		z += q
	q += x
	x += q
	if (x - q) % 2 != 0:
		z += (x - q)
	print(z)

#import sys

#q = 0
#x = 1

#question = input("How many terms of the Fibonacci sequence do you want?")
#while question.isdigit() == False:
	#question = input("How many digits?")
#if int(question) % 2 == 0:
	#for r in range(round(int(question) / 2)):
		#q += x
		#print(q)
		#x += q
		#print(x)
#if int(question) % 2 != 0:
	#for r in range(round((int(question)) / 2)):
		#q += x
		#print(q)
		#x += q
		#print(x)

