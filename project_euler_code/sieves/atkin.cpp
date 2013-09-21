//Made from Wikipedia's description of the algorithm


#include<iostream>
#include<math.h>
#include<bitset>
#include<ctime>

using namespace std;

int main() {

	clock_t start;
	double duration;
	start = clock();

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

	int fval;

	for(fval = 5; fval < limit; fval++) {
		if(p[fval] != 0) {
			cout << fval << endl;
		}
	}

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << endl << duration << " seconds\n";

}
