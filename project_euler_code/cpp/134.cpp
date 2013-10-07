//Made from Wikipedia's description of the algorithm


#include<iostream>
#include<math.h>
#include<cmath>
#include<bitset>
#include<vector>

using namespace std;

const unsigned int limit = 500000;
//const unsigned int limit = 10;

int main() {

	const int limsq = sqrt(limit);
	int x, y;
	int n, nm;
	bitset<limit>& p = *(new bitset<limit>());
	vector<int> plist;

	for(x = 1; x < limsq; x++) {

		for(y = 1; y < limsq; y++) {

			n = (4 * (x * x)) + (y * y);
			if(n <= limit && (n % 12 == 1 || n % 12 == 5)) {
				p.flip(n);
			}

			n = (3 * (x * x)) + (y * y);
			if(n <= limit && (n % 12 == 7)) {
				p.flip(n);
			}

			n = (3 * (x * x)) - (y * y);
			if((x > y) && (n <= limit) && (n % 12 == 11)) {
				p.flip(n);
			}
		}
	}

	for(n = 5; n < limsq; n++) {
		if(p[n] == 1) {
			nm = n * n;
			while(nm < limit) {
				p[nm] = 0;
				nm += n;
			}
		}
	}

	unsigned int f;
	long unsigned int p1, p2, p1len;
	long unsigned int psum = 0;
	long unsigned int s, z;

	for(f = 5; f < limit; f++) {
		if(p[f] != 0) {
			plist.push_back(f);
		}
	}
	for(f = 0; f < plist.size() - 1; f++) {
		p1 = plist[f];
		p2 = plist[f + 1];
		z = 2;
		p1len = floor(log10(abs(p1))) + 1;
		while(true) {
			if(((p2 * z) - p1) % int(pow(10, p1len)) == 0) {
				cout << p1 << " " << p2 << " " << p2 * z << endl;
				psum += p2 * z;
				break;
			}
			z++;
		}
	}
	cout << psum << endl;

}
