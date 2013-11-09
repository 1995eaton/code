#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int main() {

	clock_t start_time = clock();
	vector<int> psum(1000, 0);

	for(size_t c = 3; c <= 1000; ++c) {
		for(size_t b = 2; b < c; ++b) {
			for(size_t a = 1; a < b; ++a) {
				if(a + b + c > 1000) { break; }
				if((a*a) + (b*b) == (c*c)){ psum[a + b + c]++; }
			}
		}
	}
	for(size_t x = 0; x <= psum.size(); ++x) {
		if(psum[x] > 3) { cout << "p: " << x << " total solutions: " << psum[x] << endl; }
	}
	cout << "\nFinished in " << (clock() - start_time) / (double) CLOCKS_PER_SEC << endl;
	return 0;
}
