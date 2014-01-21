def Tri(lim):
 s = 0
 for i in range(1, lim + 1):
  s += i
  yield s

def main():
 for i in list(Tri(50000)):
  c = 0
  if not i % 2:
   c = 1
  for i2 in range(1, int(i**0.5)):
   if not i % i2:
    c += 2
   if c >= 500:
    return i

print(main())
