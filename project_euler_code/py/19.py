daysofmonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
isleap, count, dayofweek = 0, 0, 0

for year in range(1901, 2001):
 firstofmonth = 0
 daysofmonth[1] = 28
 if isleap == 4:
  daysofmonth[1] = 29
  isleap = 0
 isleap += 1
 for days in range(365):
  if days == sum(daysofmonth[:firstofmonth]):
   firstofmonth+=1
   if dayofweek == 6:
    count+=1
  dayofweek += 1
  if dayofweek == 7:
   dayofweek = 0

print(count)
