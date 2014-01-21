import numpy
def Erat(lim):
    sieve = [[] for i in range(2, lim + 1)]
    for i, n in enumerate(sieve):
        if i != 0 and i != 1:
            if not sieve[i]:
                x = i
                while x < len(sieve):
                    sieve[x].append(i)
                    x += i
    return sieve
def main(lim = 10**7):
    pmin = [0, 0, lim]
    for i, n in enumerate(Erat(lim)):
        phi = 1
        for x in n:
            phi *= (1 - (1/x))
        phi = int(i*phi)
        if phi != 0 and phi != 1:
            if i/phi < pmin[2]:
                if sorted(str(i)) == sorted(str(phi)):
                    pmin = [i, phi, i/phi]
                    print(i, phi, pmin)
main()
