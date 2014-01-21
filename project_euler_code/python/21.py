
totsum = 0
for x in range(1,10001):
 sum_fact = 0
 sum2_fact = 0
 for y in range(x):
  if y != 0 and x % y == 0:
   sum_fact += y
 for z in range(sum_fact):
  if z !=0 and sum_fact % z == 0:
   sum2_fact += z
 if x == sum2_fact and x != sum_fact:
  print(x, sum_fact)
  totsum += x
print(totsum)
