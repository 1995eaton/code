import numpy


def Erat(lim):
    sieve = numpy.ones((lim, ), dtype=numpy.bool)
    for i in range(2, int(lim**0.5)):
        sieve[i*2::i] = False
    return sieve[2::]


for index, i in enumerate(Erat(200000)):
    if i:
        c += 1
        if c == 10001:
            return index + 2
