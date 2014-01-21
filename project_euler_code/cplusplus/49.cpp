#include<iostream>
#include<bitset>
#include<vector>
#include<set>
#include<boost/lexical_cast.hpp>

using namespace std;

int main() {

	int xx, digit, temp;
	bitset<10000> sieve; sieve.set();
	vector<int> permcount(10000, 0);
	for(size_t x = 2; x < 1000; ++x) {
		xx = x * x;
		while(xx < 10000) {
			sieve.reset(xx);
			xx+=x;
		}
	}
	for(size_t x = 1000; x < sieve.size(); ++x) {
		if(sieve[x] == 1) { 
			string sortx = "";
			for(digit = 0; digit < 10; ++digit) {
				for(temp = x; temp > 0; temp /= 10) {
					if(temp % 10 == digit) {
						if(digit == 0) { break; }
						sortx += boost::lexical_cast<string>(digit);
					}
				}
			}
			if(sortx.length() > 3) {
				//cout << sortx << endl;
				permcount[boost::lexical_cast<int>(sortx)]++;
			}
		}
	}
	for(size_t x = 0; x < permcount.size(); ++x) {
		if(permcount[x] > 4) {
			cout << x << " " << permcount[x] << endl;
			int xc = x;
			vector<int> temp;
			for(size_t xx = 0; xx < 12; ++ xx) {
				if(sieve[xc] == 1) { temp.push_back(xc);}
				xc = ((xc - (xc % 10)) / 10) + ((xc % 10) * 1000);
				if(sieve[xc] == 1) { cout << xc << endl;}
				//if(xc = x){ break; }
			}
			sort( temp.begin(), temp.end() );
			temp.erase( unique( temp.begin(), temp.end() ), temp.end() );
			for(size_t fuck = 0; fuck < temp.size(); ++fuck) {
				cout << temp[fuck] << endl;
			}
		}
	}
	
	return 0;
}
