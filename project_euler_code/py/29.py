
from array import array

p = set([])

for a in range(2,101):
 for b in range(2,101):
  p.add(a**b)
print(len(p))

