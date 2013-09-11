#!/usr/bin/python

import re
import itertools
import enchant

enchant_lang = enchant.Dict("en_US")

def solver(_word_):
	_list = []
	words = re.sub("[^\w]", " ", _word_).split()
	same = 0
	for n in words:
		for subset in itertools.permutations(n, r=len(n)):
			subset = "".join(subset).split()
			for x in subset[:len(subset)]:
				if enchant_lang.check(str(x)) == True:
					if str(x) not in _list:
						_list.append(str(x))
	print(_list)

word_input = input("Enter a list of scrambled words separated by spaces: ")
solver(word_input)
