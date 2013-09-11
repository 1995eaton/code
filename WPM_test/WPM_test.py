#!/usr/bin/python

import os
import sys
import time
from termcolor import colored, cprint
from collections import Counter

########################################################################
#                                  Getch                               #
########################################################################

class _Getch:
    """Gets a single character from standard input.  Does not echo to the screen."""
    def __init__(self):
        try:
            self.impl = _GetchWindows()
        except ImportError:
            self.impl = _GetchUnix()

    def __call__(self): return self.impl()


class _GetchUnix:
    def __init__(self):
        import tty, sys

    def __call__(self):
        import sys, tty, termios
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch


class _GetchWindows:
    def __init__(self):
        import msvcrt

    def __call__(self):
        import msvcrt
        return msvcrt.getch()


getch = _Getch()

########################################################################


########################################################################
#                                  Text                                #
########################################################################

text1 = "In my younger and more vulnerable years my father gave me some advice that I\'ve been turning over in my mind ever since. \"Whenever you feel like criticizing any one,\" he told me, \"just remember that all the people in this world haven\'t had the advantages that you\'ve had.\" He didn\'t say any more, but we\'ve always been unusually communicative in a reserved way, and I understood that he meant a great deal more than that. In consequence, I\'m inclined to reserve all judgments, a habit that has opened up many curious natures to me and also made me the victim of not a few veteran bores. The abnormal mind is quick to detect and attach itself to this quality when it appears in a normal person, and so it came about that in college I was unjustly accused of being a politician, because I was privy to the secret griefs of wild, unknown men. Most of the confidences were unsought — frequently I have feigned sleep, preoccupation, or a hostile levity when I realized by some unmistakable sign that an intimate revelation was quivering on the horizon; for the intimate revelations of young men, or at least the terms in which they express them, are usually plagiaristic and marred by obvious suppressions. Reserving judgments is a matter of infinite hope. I am still a little afraid of missing something if I forget that, as my father snobbishly suggested, and I snobbishly repeat, a sense of the fundamental decencies is parcelled out unequally at birth."
list1 = list(text1)

########################################################################

def main():
	#for c in list1:
		#get = getch()
		#if get == c:
			#print("good")
	i = 0
	errors = 0
	print(text1)
	start_time = time.time()
	while i < len(text1):
		if time.time() - start_time > 60:
			text1_completed = text1[0:i]
			wordcount = Counter(text1_completed.split())
			lettercount = len(text1_completed)
			break
		if text1[int(i)] == getch():
			os.system('clear')
			print(text1[0:i + 1], colored(text1[i + 1], 'blue', 'on_red'), text1[i + 2:], sep='', end='\r')
			sys.stdout.flush()
			i = i + 1
		else:
			os.system('clear')
			errors = errors + 1
			print(text1[0:i], colored(text1[i], 'red', 'on_white'), text1[i + 1:], sep='', end='\r')
			sys.stdout.flush()

	print("\n\nYour typing speed is:", len(wordcount), "words/minute")
	try:
		print("You made ", errors, " errors, giving you an accuracy of ", ((lettercount - errors) / lettercount) * 100, '%', sep='')
	except:
		print("You made ", errors, " errors, giving you an accuracy of 0%", sep='')

main()
