#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<boost/lexical_cast.hpp>

using namespace std;

int main() {

	clock_t start_time = clock();
	streamsize ss = cout.precision();

	vector<vector <double>> digitSums(100);
	vector<double> results;
	int i0, i1, i2, dsum;
	const int max_dsum_size = 100;
	const int max_power = 9;

	for(i0 = 2; i0 < max_dsum_size; ++i0) {
		vector<double> powers;
		for(i1 = 2; i1 < max_power; ++i1) {
			powers.push_back((double)pow(i0, i1));
		}
		digitSums[i0] = powers;
	}

	for(i0 = 0; i0 != digitSums.size(); ++i0) {
		for(i1 = 0; i1 != digitSums[i0].size(); ++i1) {
			dsum = 0;
			string powers_str = boost::lexical_cast<string>(digitSums[i0][i1]);
			for(i2 = 0; i2 < powers_str.length(); ++i2) {
				dsum += powers_str[i2] - '0';
			}
			if(dsum == i0) {
				results.push_back(digitSums[i0][i1]);
			}
		}
	}

	sort(results.begin(), results.end());

	for(i0 = 0; i0 != results.size(); ++i0) {
		cout.precision(50);
		cout << i0+1 << " " << results[i0] << endl;
	}

	cout.precision(ss);
	cout << (clock() - start_time) / (double) CLOCKS_PER_SEC << endl;

	return 0;

}
