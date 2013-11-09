#this is terrible, I know
import math, numpy
def Erat(n):
    sieve = numpy.ones((n, ), dtype=bool)
    for i in range(2, math.ceil(n**0.5)):
        sieve[i*2::i] = 0
    return sieve, [index for index, i in enumerate(sieve) if i == 1 and index >= 2]
primes = Erat(20000)
concatprimes = Erat(99500000)
def concat(n, n2):
    i1 = int(str(n) + str(n2))
    i2 = int(str(n2) + str(n))
    if i1 < len(concatprimes[0]) - 1 and i2 < len(concatprimes[0]) - 1 and (concatprimes[0])[i1] and (concatprimes[0])[i2]:
        return True

tested = []
lowestsum = 10**6
for p in primes[1]:
    for p1 in primes[1]:
        if concat(p, p1):
            temp = [p, p1]
            for p2 in primes[1]:
                if concat(p, p2) and concat(p1, p2):
                    temp = [p, p1, p2]
                    for p3 in primes[1]:
                        if concat(p, p3) and concat(p1, p3) and concat(p2, p3):
                            temp = [p, p1, p2, p3]
                            print(temp)
                            for p4 in primes[1]:
                                #if concat(p, p4) and concat(p1, p4) and concat(p2, p4) and concat(p3, p4):
                                if concat(p, p4) and concat(p1, p4) and concat(p2, p4):
                                    if concat(p3, p4):
                                        temp = [p, p1, p2, p3, p4]
                                        print(temp, sum(temp))
