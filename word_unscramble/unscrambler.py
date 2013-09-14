#!/usr/bin/python

from collections import Counter; import sys; import re
try:

	do = open("dictionary", "r")
	try:

		infile_open = open(sys.argv[1], "r")
		infile_read = infile_open.read()
		infile_clear = [x for x in re.sub("\W", " ", infile_read.lower()).split(" ") if len(x) != 0]
		for x in str.split(do.read()):
			for y in infile_clear:
				if len(x) == len(y) and Counter(x) == Counter(y):
					print(x)

	except FileNotFoundError:

		for x in str.split(do.read()):
			for y in sys.argv:
				if len(x) == len(y) and Counter(x) == Counter(y):
					print(x)

except FileNotFoundError: print("Error: dictionary file not found")
