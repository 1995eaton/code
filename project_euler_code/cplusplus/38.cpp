/*

Take the number 192 and multiply it by each of 1, 2, and 3:

	192 × 1 = 192
	192 × 2 = 384
	192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

*/

#include<iostream>
#include<iomanip>
#include<string>
#include<boost/lexical_cast.hpp>
#include<ctime>

using namespace std;

static char digits[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {

	clock_t start_time = clock();

	for(size_t i = 0; i < 10000; ++i) {

		string i_str = boost::lexical_cast<string>(i);
		bool isPandigital = 1;
		int ii = 2;

		while(i_str.length() < 9) {
			i_str += boost::lexical_cast<string>(i * ii);
			ii++;
		}

		if(i_str.length() != 9 || count(i_str.begin(), i_str.end(), '0') != 0) {continue;}

		for(size_t x = 0; x < 9; ++x) {
			if(count(i_str.begin(), i_str.end(), digits[x]) > 1) {
				isPandigital = 0;
				break;
			}
		}

		if(isPandigital == 1) {
			cout << left << setw(4) << i << " * " << "(2 --> " << ii <<  ")\t\b\b\b\b\b\b" <<  "concatenated" << " == " << i_str << endl;
		}
	}
	cout << "\nFinished in: " << (clock() - start_time) / (double)CLOCKS_PER_SEC << "s\n";

	return 0;

}
