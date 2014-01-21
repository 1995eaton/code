a, b, c = 1, 1, 0
for i in 0..Float::INFINITY
   a, b = a+b, a
   c += a if a.even?
   (puts c; break) if a >= 4000000
end
