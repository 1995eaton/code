import time
def palcheck(x):
 x = str(x)
 if len(x) % 2 == 0:
  if x == x[::-1]:
   return True
 else:
  if x == x[::-1]:
   return True
 return False
def b10to2(y):
 b2 = str("")
 t = 0
 while 2**t < y:
  t += 1
 for x in range(t + 1,-1,-1):
  if 2**x <= y:
   b2 += "1"
   y -= 2**x
  else:
   b2 += "0"
 return int(b2)

start_time = time.time()
print(sum([x for x in range(1000000) if palcheck(x) == True and palcheck(b10to2(x)) == True]))
print("Completed in", time.time() - start_time, "seconds")
