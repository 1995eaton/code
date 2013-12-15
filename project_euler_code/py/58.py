import random, sys

def mRabinTest(num0, loops):

	if num0 < 2 or num0 % 2 == 0:
		return False
	s_, divisor = 0, num0-1

	while True:
		quotient, remainder = divmod(divisor, 2)
		if remainder == 1:
			break
		s_, divisor = s_+1, quotient
	if 2**s_ * divisor != num0-1:
		return False

	def tryComposite(num1):
		if pow(num1, divisor, num0) == 1:
			return False
		for i_ in range(s_):
			if pow(num1, 2**i_ * divisor, num0) == num0-1:
				return False
		return True

	for i_ in range(loops):
		num1 = random.randrange(2, num0)
		if tryComposite(num1):
			return False
	return True

def main(index=1, i_=2, ecount=0, vertcount=0, pcount=0):

	while True:
		vertcount += 1
		if pcount/vertcount < 0.1:
			if index > 3:
				return [index, index**.5, pcount/vertcount]

		if ecount != 4 and mRabinTest(index, 3):
			pcount+=1
		ecount, index = ecount+1, index+i_

		if ecount == 4:
			i_, ecount = i_+2, 0

print(main())
