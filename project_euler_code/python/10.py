import numpy


def Erat(lim):
    sieve = numpy.ones((lim, ), dtype=numpy.bool)
    for i in range(2, int(lim**0.5)):
        sieve[i**2::i] = False
    return sum([index for index, i in enumerate(sieve[2:])
               if i and index < 2000000])

print(Erat(2100000))
