count = 0
for x in range(1, 100):
 for y in range(1, 100):
  if len(str(x**y)) < y or len(str(x**y)) > y:
   break
  count+=1
  print(x, "^", y, " = ", x**y, sep='')
print(count)
