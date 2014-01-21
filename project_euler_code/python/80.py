import math; from decimal import *
import re
nnatural = [i for i in range(1, 101) if math.floor(i**0.5)**2 != i]
getcontext().prec = 105
ctotal = 0
for i in nnatural:
    digits = Decimal(i).sqrt()
    digits = re.sub("\.", "", str(digits))
    digits = digits[:100]
    total = 0
    for d in digits:
        total += int(d)
    ctotal += total
print(ctotal)
