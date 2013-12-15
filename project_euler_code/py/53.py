
def Factorial(n):
 prod = 1
 for i in range(2, n + 1):
  prod*=i
 return prod

def Combinations(n, r):
 return int(Factorial(n)/(Factorial(r)*Factorial(n-r)))

def main(csum = 0):
 for n in range(1, 101):
  for r in range(1, n):
   result = Combinations(n, r)
   print(result)
   if result > 10**6:
    csum+=1
 print('\n', csum, sep='')

main()
