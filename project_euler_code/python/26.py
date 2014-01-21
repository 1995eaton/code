from decimal import *
import time
start_time = time.time()
fuck = []
m = 0
getcontext().prec = 2000
decList = [[len(str(x)), Decimal(1) / Decimal(x), x] for x in range(1, 1001) if x % 10 == 3 or x % 10 == 1 or x % 10 == 9]
for x in decList:
 sx = (str(x[1]))[1+x[0]:-1]
 for i in range(2,1000):
  if sx[0:i] == sx[i+1:2*(i)+1]:
   if i > m:
    m = i
    print(x[2])
   break
print("\n", "Finished in ", time.time() - start_time, sep='')
