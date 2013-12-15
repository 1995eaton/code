from collections import Counter; import itertools, time

def digitTest(x, c=0, n = 1):
 while Counter(str(x)) == Counter(str(x * n)):
  c+=1; n+=1
 return c

def main(n = 1245879):
 for x in itertools.permutations(str(n)):
  y = int("".join(x))
  if digitTest(y) > 3:
   print(y, digitTest(y))
   return 0

start_time = time.time()
main()
print('\n', time.time() - start_time, sep='')
