#include<stdio.h>
#include<stdbool.h>

bool isPalindrone(n) {
	int n_orig = n;
	int n_rev = 0;
	while(n_orig > 0) {
		n_rev = n_rev * 10 + n_orig % 10;
		n_orig /= 10;
	}
	return n == n_rev;
}


int main() {
	int max = 0;
	for(int a = 100; a < 1000; ++a) {
		if(a % 10 == 0) {
			continue;
		}
		for(int b = a+1; b < 1000; ++b) {
			if(b % 10 == 0) {
				continue;
			}
			int c = a*b;
			if(isPalindrone(c)) {
				if(c > max) {
					max = c;
					printf("%d\n", c);
				}
			}
		}
	}
	return 0;
}
