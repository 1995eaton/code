#include<iostream>
#include<bitset>
#include<math.h>
#include<ctime>

using namespace std;

int main() {

	clock_t start_time = clock();

	const unsigned limit = 6000;
	const unsigned sqlim = round(sqrt(limit));

	bitset<limit> sieve; sieve.set();
	bitset<limit> composites;

	for(size_t x = 2; x < sqlim; ++x) {
		for(size_t xx = x * x; xx < limit; xx+=x) {
			sieve.reset(xx);
		}
	}

	for(size_t x = 1; x < sieve.size(); x+=2) {
		if(!sieve[x]) {composites[x] = 1;}
	}

	for(size_t x = 1; 2*(x*x) < limit; ++x) {
		unsigned xx = 2*(x*x);
		for(size_t x = 1; x + xx < limit; x+=2) {
			if(sieve[x]) {composites[xx + x] = 0;}
		}
	}

	for(size_t x = 1; x < limit; ++x) {
		if(composites[x]) {
			cout << x << "\nFinished in " << (clock() - start_time) / (long double) CLOCKS_PER_SEC << endl; return 0;
		}
	}
}
