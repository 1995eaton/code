
limit = 10000
plist = set([])
for x in range(1,limit + 1):
 p = int((x * ((3 * x) - 1)) / 2)
 plist.add(p)
for x in plist:
 for y in plist:
  if x != y and x + y in plist:
   if abs(x - y) in plist:
    print(x, y)
    print(abs(x - y))
