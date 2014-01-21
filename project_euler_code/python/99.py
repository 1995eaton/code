import os; from math import floor, log10

base_exp = [i.split(",") for i in (open("base_exp.txt", "r").read()).rsplit()]
Dmax = 0
for index, i in enumerate(base_exp):
	b = int(i[0]); e = int(i[1])
	D = int(floor(1 + (e * log10(b))))
	if D > Dmax or D == Dmax:
		Dmax = D
print("Line ", index + 1, " | ", b, "**", e, " | Digit length: ", Dmax, sep='')
