def squareTest(n)
   h = n.to_i&0xF
   if h != 2 and h != 3 and h != 5 and h != 6 and h != 7 and h != 8
      return ((n**0.5).floor)**2 == n
   end
   return false
end

def FermatFactor(n, r1, r2)
   a = (n**0.5).ceil
   a+=1 while squareTest(a*a-n) == false
   b = (a*a-n)**0.5
   return [a-b, a+b]
end

n = 600851475143
f = FermatFactor(n, 0, 0)
r1, r2 = f[0], f[1]
while r1 != 1 and r2 != 1
   puts r1, r2
   f = FermatFactor(r1, r1, r2)
   r1, r2 = f[0], f[1]
end
