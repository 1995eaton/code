# A python interpretation of the digit extraction properties of the Baily-Borwein-Plouffe formula
# http://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula

from math import floor
from sys import argv

def mEXP(base, exponent, modulus):
 result = 1
 while exponent > 0:
  if exponent % 2 == 1:
   result = (result * base) % modulus
  exponent >>= 1
  base = (base**2) % modulus
 return result

def BBP(d):
 def expand(j):
  S, temp = 0, 0
  for k in range(0, d+1):
   S += mEXP(16, d-k, (8*k + j)) / (8*k + j)
  k = d+1
  while True:
   S += (16**(d-k)) / (8*k + j)
   if temp == S:
    break
   temp = S
   k += 1
  return S
 result = 4*expand(1)-2*expand(4)-expand(5)-expand(6)
 result -= floor(result)
 while result > -1 and result < 1:
  result *= 16
 return hex(int(result))

print(BBP(int(argv[1])))
