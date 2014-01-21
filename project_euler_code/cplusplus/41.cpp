#include<sstream>
#include<iostream>
#include<bitset>
#include<vector>
#include<math.h>

using namespace std;

template<typename OutputIterator>
void atkin(OutputIterator out) {

	const long int limit = 7652420;
	const int lsquare = sqrt(limit);
	int x, y, n, nn;
	bitset<limit> bit;

	for(x = 1; x < lsquare; x++) {
		for(y = 1; y < lsquare; y++) {
			n = (4 * (x * x)) + (y * y);
			if(n <= limit && (n % 12 == 1 || n % 12 == 5)) {
				bit.flip(n);
			}
			n = (3 * (x * x)) + (y * y);
			if(n <= limit && n % 12 == 7) {
				bit.flip(n);
			}
			n = (3 * (x * x)) - (y * y);
			if(x > y && (n <= limit && n % 12 == 11)) {
				bit.flip(n);
			}
		}
	}

	for(n = 5; n < lsquare; n++) {
		if(bit[n] == 1) {
			nn = n * n;
			while(nn < limit) {
				bit.reset(nn);
				nn += n;
			}
		}
	}
	long long int fval;
	for(fval = 5; fval < limit; fval++) {
		if(bit[fval] == 1) {
			*(out++) = fval;
		}
	}

}

int main() {

	int primeindex;
	vector<long long int> primelist;

	atkin(back_inserter(primelist));

	int index, pnum, plength, p10, t, p10sum, p10mult, numsum, nummult;

	for(index = 0; index < primelist.size(); index++) {
		pnum = primelist[index];
		p10sum = 0;
		p10mult = 1;
		numsum = 0;
		nummult = 1;
		plength = 0;
		p10 = pnum;
		while(p10 >= 1) {
			p10sum += p10 % 10;
			p10mult *= p10 % 10;
			p10 -= p10 % 10;
			p10 /= 10;
			plength++;
		}
		for(t = 1; t <= plength; t++) {
			numsum += t;
			nummult *= t;
		}
		if(numsum == p10sum && nummult == p10mult) {
			cout << pnum << endl;
		}
	}
}
