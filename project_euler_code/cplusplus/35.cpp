//g++ -O3 -march=native -std=c++11
//0.026s

#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>

using namespace std;

int main() {

	clock_t start_time = clock();
	unsigned const limit = 1000000;
	int cpt = 0; //total circular primes found
	int xcopy;
	vector<bool> sieve(limit, true);

	//begin calculating primes
	for(size_t x = 2; x <= round(sqrt(limit)); ++x) {
		xcopy = x * 2;
		while(xcopy < limit) {
			sieve[xcopy] = false;
			xcopy += x;
		}
	}

	//check circularity
	vector<int> cirprimes;
	for(size_t x = 2; x < limit; ++x) {
		if(sieve[x] == true) {
			xcopy = x;
			int xlen = floor(log10(abs(x)));
			do {
				if(xcopy != 2 && (xcopy % 10) % 2 == 0 || sieve[xcopy] == 0) {xcopy = 0; break;} //if last digit is even or rotation != prime
				xcopy = ((xcopy % 10) * (pow(10, xlen))) + (xcopy - (xcopy % 10)) / 10; //rotate
			} while(xcopy != x);
			if(xcopy != 0) {cpt++; cout << x <<  endl;}
		}
	}

	cout << endl << cpt << endl << (clock() - start_time) / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
