#!/usr/bin/python
import math, numpy, re
def Erat(lim):
    sieve = numpy.ones((lim, ), dtype=bool)
    for i in range(2, round(lim**0.5)):
        sieve [i*2::i] = 0
    sieve[:2] = 0
    return sieve

lim = 1000000
sieve = Erat(lim)
checked = numpy.zeros((lim, ), dtype=bool)
for i, n in enumerate(sieve):
    if n == 1:
        if not checked[i]:
            if len(str(i)) > 1:
                for r in str(i):
                    c = 1
                    for r2 in range(0, 10):
                        changed = re.sub(str(r), str(r2), str(i))
                        if int(changed) < lim:
                            if changed[0] != '0' and sieve[int(changed)]:
                                c += 1
                                checked[int(changed)] = 1
                                if c == 9:
                                    print(c, changed)
