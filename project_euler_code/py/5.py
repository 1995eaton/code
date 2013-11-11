def main(n = 2, t = [11, 13, 16, 17, 19]):
 while True:
  div = 2520*n
  n += 1
  c = 0
  for i in t:
   if not div % i:
    c += 1
  if c == 5:
   return div

print(main())
