
def Lyrchrel(n, tries = 0):
 if int(str(n)[::-1]) == n:
  n+=int(str(n)[::-1])
  tries+=1
 while int(str(n)[::-1]) != n:
  tries+=1
  if tries == 50:
   return True
  n+=int(str(n)[::-1])
 return None

def main(limit = 10000, lcount = 0):
 for x in range(1, limit):
  if Lyrchrel(x) == True:
   print(x)
   lcount+=1

 print('\nTotal:', lcount)

main()
