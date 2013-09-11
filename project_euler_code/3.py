#!/usr/bin/python

import sys

list1 = []
num = 600851475143

#def main():
	#question = input("How many digits?")
	#for x in range(int(question)):
		#count = 0
		#for y in range(1,x):
			#if x % y == 0:
				#count += 1
		#if count < 2:
			#list1.append(x)
			##print(x)
	##print(list1)
	#for g in list1[1:len(list1)]:
		#if num % g == 0:
			#print(g)

def main():
	question = input("Number:")
	while question.isdigit() == False:
		question = input("Number:")
	count = 0
	for y in range(1,int(question)):
		if int(question) % y == 0:
			for q in range(1,int(question)):
				count = 0
				if y % q == 0:
					count += 1
				print(count)
				if count < 2:
					print(q)
main()
