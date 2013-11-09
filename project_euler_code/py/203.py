import numpy

def erat(limit):
    sieve = numpy.ones((limit, ), dtype=numpy.bool)
    for i in range(2, int(limit**0.5)+1):
        sieve[i*2::i] = False
    return [index for index, i in enumerate(sieve) if i == 1][2:]

primes = [i**2 for i in erat(50)]
rows = [[1, 1] for i in range(50)]
rset = set([])

for index, i in enumerate(rows):
    for r in range(0, len(i) - 1):
        if index+1 < len(rows):
            rows[index+1].insert(r + 1, i[r]+i[r+1])
            rset.add(r+1); rset.add(i[r]+i[r+1])

for i in sorted(rset):
    for i1 in primes:
        if i1 <= i:
            if i % i1 == 0:
                if i in rset:
                    rset.remove(i)

print(sum(rset))
