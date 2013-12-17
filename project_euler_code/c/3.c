#include <stdio.h>
#include <math.h>

unsigned long squareTest(unsigned long n) {
	int h = n & 0xF;
	if(h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8) {
		return pow(floor(sqrt(n)), 2) == n;
	}
	return 0;
}

void FermatFactor(unsigned long n, unsigned long *r1, unsigned long *r2) {
	unsigned long a = ceil(sqrt(n));
	while (squareTest(a*a - n) == 0) { a++; }
	unsigned long b = sqrt(a*a - n);
	*r1 = a-b; *r2 = a+b;
}

int main() {
	unsigned long n = 600851475143;
	unsigned long r1, r2 = 0;
	FermatFactor(n, &r1, &r2);
	while(r1 != 1 && r2 != 1) {
		printf("%lu\n%lu\n", r1, r2);
		FermatFactor(r1, &r1, &r2);
	}
	return 0;
}
