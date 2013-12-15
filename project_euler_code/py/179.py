import time, numpy

start_time = time.time()
limit = 10**7
c = 0
factors = numpy.zeros(limit + 1)

for i in range(2, int(limit/2)):
 factors[i*2:limit:i] += 1

for i in range(0, limit):
 if factors[i] == factors[i + 1]:
  #if c > 1:
   #print(i, i + 1)
  c+=1

print(c-2)
print(time.time() - start_time)
