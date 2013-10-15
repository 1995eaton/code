/*
   The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

   Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

   d2d3d4=406 is divisible by 2
   d3d4d5=063 is divisible by 3
   d4d5d6=635 is divisible by 5
   d5d6d7=357 is divisible by 7
   d6d7d8=572 is divisible by 11
   d7d8d9=728 is divisible by 13
   d8d9d10=289 is divisible by 17

   Find the sum of all 0 to 9 pandigital numbers with this property.
   */

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<boost/lexical_cast.hpp>

using namespace std;

int main() {

	clock_t start_time = clock();
	static int primes[7] = {2, 3, 5, 7, 11, 13, 17};
	unsigned long pandigital_sum = 0;
	bool isdivisible;
	string pnums = "1023456789";
	const char *pchar = pnums.c_str();

	do {

		isdivisible = 1;
		if(pchar[5] % 5 == 0 || pchar[3] % 2 != 0 || pchar[7] % 2 != 0){continue;}
		for(size_t x = 1; x < 8; ++x) {
			if(boost::lexical_cast<unsigned>(pnums.substr(x, 3)) % primes[x - 1] != 0) {isdivisible = 0; break;}
		}

		if(isdivisible == 1) {
			cout << pnums << endl;
			pandigital_sum += boost::lexical_cast<unsigned>(pnums);
		}

	} while(next_permutation(pnums.begin(), pnums.end()));

	cout << "The total sum: " << pandigital_sum << "\nFinished in " << (clock() - start_time) / (long double)CLOCKS_PER_SEC << "s\n\n";
	return 0;

}
