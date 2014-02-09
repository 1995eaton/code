pe2 n a b
  | a > 4000000 || b > 4000000 = n
  | otherwise = let a1 = b
                    b1 = a + b
                in if even a1
                     then pe2 (n + a1) a1 b1
                     else pe2 n a1 b1

main = print $ pe2 0 0 1
