#include<iostream>
#include<math.h>
#include<cmath>
#include<bitset>
#include<ctime>

using namespace std;

int main() {

	const int limit = 1000000;
	const int limsq = sqrt(limit);
	int x, y;
	int n, nm;
	bitset<limit> p;

	for(x = 1; x < limsq; x++) {

		for(y = 1; y < limsq; y++) {

			n = (4 * (x * x)) + (y * y);
			if(n <= limit && (n % 12 == 1 || n % 12 == 5)) {
				p.flip(n);
			}

			n = (3 * (x * x)) + (y * y);
			if(n <= limit && (n % 12 == 7)) {
				p.flip(n);
			}

			n = (3 * (x * x)) - (y * y);
			if((x > y) && (n <= limit) && (n % 12 == 11)) {
				p.flip(n);
			}
		}
	}

	for(n = 5; n < limsq; n++) {
		if(p[n] == 1) {
			nm = n * n;
			while(nm < limit) {
				p[nm] = 0;
				nm += n;
			}
		}
	}

	int a, b, c;
	int cmax = 0;

	for(a = 999; a > -10000; a--) {
		for(b = 999; b > -10000; b--) {
			c = 0;
			int eqn = (c * c) + (a * c) + b;
			while(eqn > 0 && p[eqn] != 0) { 
				if(abs(c) > cmax) {
					cout << a << " & " << b << " = " << eqn << " and are on iteration number " << c << endl;
					cmax = abs(c);
				}
				c++;
				eqn = (c * c) + (a * c) + b;
			}
		}
	}


}
