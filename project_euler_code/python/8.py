import os

n = [int(i) for i in list(open("bn.txt", "r").read()) if i != '\n']
m = 0

for i in range(0, len(n)):
 prod = 1
 for i2 in n[i:i+5]:
  prod *= i2
 if prod > m:
  m = prod
print(m)
