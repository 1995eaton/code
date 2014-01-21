#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int main() {

	std::clock_t s;
	double d;
	s = std::clock();

	unsigned int maxRecord = 0;
	unsigned int upperBound = 1000000;
	std::vector<unsigned int> chainLen(upperBound + 1, 0);

	for(size_t x = 1; x < upperBound; ++x) {

		unsigned int n = x;
		unsigned int max = 0;

		while(n != 1) {

			if(n < upperBound && chainLen[n] != 0 && chainLen[n] + max < maxRecord) {break;}
			if(n % 2 == 0) {n /= 2;}
			else {n = (n * 3 + 1);}
			max++;

		}

		chainLen[x] = max;

		if(max >= maxRecord) {
			maxRecord = max;
			cout << x << endl;
		}
	}

	d = (std::clock() - s) / (double)CLOCKS_PER_SEC;
	cout << "Finished in " << d << " seconds." << endl;
	return 0;

}
