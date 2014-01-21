
import math

limit = 10**8
grouplimit = int(math.sqrt(limit)) + 1
numset = set([])

for g in range(2,grouplimit + 1):
 i = 1
 for x in range(1, limit + 1):
  numgroup = 0
  for num in range(i, i + g):
   if numgroup > limit:
    break
   numgroup += num**2
  i+=1
  if numgroup > limit:
   break
  if numgroup < limit and str(numgroup)[::-1] == str(numgroup):
   numset.add(numgroup)

print(numset)
print(sum(numset))
