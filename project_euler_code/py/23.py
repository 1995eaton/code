
import numpy
from termcolor import colored

def factor(lim):
    sieve = numpy.zeros(lim)
    for i in range(1, round(lim/2)):
        sieve[i*2::i] += i
    return sieve

f = factor(45000)

ss = numpy.ones((len(f)*2, ), dtype=bool)
s = [index for index, i in enumerate(f) if i > index]
#s.remove(0)
ohhh = 0
for i in s:
    for ii in s:
        isum = i + ii
        ss[isum] = 0
for index, i in enumerate(ss):
    if index < 30150:
        if i == 1:
            ohhh += index
            print(index)
print(ohhh)
