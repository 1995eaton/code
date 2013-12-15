
from collections import Counter; import math, re, itertools
limit = 10000

def erat(limit):
 sieve = [True for x in range(1, limit + 1)]
 for x in range(2, round(math.sqrt(limit) + 1)):
  xx = x * 2
  while xx < limit:
   sieve[xx] = 0
   xx+=x
 return list([x for x in range(len(sieve) - 1) if sieve[x] == 1 and len(str(x)) == 4])
def main():
 primes = erat(10000)
 for x in primes:
  w = set([])
  temp = set([])
  for xx in list(itertools.permutations(str(x), 4)):
   if(int("".join(xx)) in primes):
    w.add(int("".join(xx)))
  if len(w) > 2:
   w = sorted(set(w))
   for x in w:
    for y in w:
     if x - y > 0:
      temp.add(x - y)
   if len(temp) == len(w) + 1:
    print(w, temp)
    break
main()

