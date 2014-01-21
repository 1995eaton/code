import numpy
def Erat(lim):
    sieve = [[] for i in range(2, lim)]
    for i, n in enumerate(sieve):
        if i != 0 and i != 1:
            if not sieve[i]:
                x = i
                while x < len(sieve):
                    sieve[x].append(i)
                    x += i
    return sieve
def main(lim = 10000000, ndivpmax = [0, 0, 0]):
    for i, n in enumerate(Erat(lim)):
        if len(n) > 2:
            phi = 1
            for x in n:
                phi *= (1 - (1/x))
            phi = int(i*phi)
            if phi != 0:
                if i/phi > ndivpmax[2]:
                    ndivpmax = [i, phi, i/phi]
                    print(ndivpmax)
main()
