//Made from Wikipedia's description of the algorithm


#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

const unsigned long long int limit = 10000000;

int main() {

	const int limsq = sqrt(limit);
	int x, y;
	int n, nm;
	bitset<limit>& p = *(new bitset<limit>());

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

	int fval;
	int newfval, newfval2;
	int test, test2, c;
	int sum = 0;
	p[2] = 1;
	p[3] = 1;
	p[5] = 1;
	for(fval = 5; fval < limit; fval++) {
		if(p[fval] != 0) {
			c = 1;
			newfval = fval;
			test = (newfval - (newfval % 10)) / 10;
			test2 = fval % int(pow(10, c));
			c++;
			while(p[test] != 0) {
				newfval = test;
				if(p[test2] == 0) {
					break;
				}
				if(test / 10 < 1 && p[test] != 0) {
					cout << fval << endl;
					sum += fval;
				}
				test2 = fval % int(pow(10, c));
				c++;
				if(p[test2] == 0) {
					break;
				}
				test = (newfval - (newfval % 10)) / 10;
			}
		}
	}
	cout << endl << sum << endl;
}
