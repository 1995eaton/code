#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

int main() {

	clock_t start_time = clock();
	const unsigned limit = 10000000;
	vector<int> numFactors(limit, 0);

	for(size_t i = 2; i < round(limit/2); ++i) {
		unsigned int ii = i * 2;
		while(ii < limit) {
			numFactors[ii]++;
			ii+=i;
		}
	}
	int c = 0;
	for(size_t i = 1; i < limit; ++i) {
		if(numFactors[i] == numFactors[i+1]) {
			cout << i << " " << i + 1 << endl;
			c++;
		}
	}
	cout << c - 1 << endl;
	cout << (clock() - start_time) / (double)CLOCKS_PER_SEC << endl;

	return 0;

}
			
