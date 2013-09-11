#!/usr/bin/python

import re
import itertools

def main(words):

	word_list = re.sub("[^\w]", " ", words).split()
	dictionary_open = open("dictionary", "r")
	dictionary_read = re.sub("[^\w]", "\n", dictionary_open.read()).split()
	found_words = []
	for n in word_list[:len(word_list)]:
		for subset in itertools.permutations(list(n), r=len(n)):
			permutations = re.sub("[^\w]", "\n", "".join(subset)).split()
			for x in permutations[:len(permutations)]:
				if x in dictionary_read:
					if x not in found_words:
						found_words.append(x)
						print(x)
words = input("Enter a list of scrambled words separated by spaces: ")
main(words)
