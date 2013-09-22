#!/usr/bin/python

import re

fo = open("num")
fr = fo.read()
fs = re.findall(r"\d{50}", fr)
q = 0
for n in range(len(fs)):
	q += int(fs[n])
print(str(q)[0:10])
