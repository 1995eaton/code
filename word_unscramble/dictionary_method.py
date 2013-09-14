#!/usr/bin/python

from collections import Counter; import sys

do = open("dictionary", "r")
print([x for x in str.split(do.read()) for y in sys.argv[1:] if len(x) == len(y) and Counter(x) == Counter(y)])
