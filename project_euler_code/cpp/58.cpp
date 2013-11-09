//Made from Wikipedia's description of the algorithm

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<ctime>

using std::cout; using std::endl;

std::vector <int> spiral(int cubesize) {

	if(cubesize % 2 == 0) {
		cout << "Choose an odd integer." << endl;
	}
	int spoint = (pow((cubesize - 2), 2)) + cubesize - 1;
	int limit = pow((cubesize), 2);
	int vhit = 0;
	std::vector<int> spirals(4);
	int n = 0;

	for(size_t i = spoint; i < limit + 1; i += cubesize - 1) {
		spirals[n] = i;
		n++;
	}

	return spirals;

}

int main() {

	clock_t start;
	double duration;
	start = clock();

	int slimit = 30001;
	unsigned int limit = (slimit * slimit) * 2;
	const int limsq = sqrt(limit);

	int x, xx;

	std::vector<bool>& p = *(new std::vector<bool>(limit));

	for (x = 2; x < limsq; x++) {
		if(p[x] == 0) {
			xx = x * x;
			while(xx < limit) {
				p[xx] = 1;
				xx += x;
			}
		}
	}

	std::vector<int> spirals;
	int c = 0;
	int q = 0;
	for(size_t n = 3; n <= slimit; n+=2) {
		spirals = spiral(n);
		q++;
		for(size_t i = 0; i < 4; ++i) {
			if(p[spirals[i]] == 0) {
				//cout << c << ": " << (double)(n+1) / 13<< "%\n";
				c++;
				double eqn = ((double)c / ((q * 4) + 1)) * 100;
				if(eqn > 0 && round(eqn) < 10) {
					std::cin.ignore();
				}
				//cout << c << ": " << (c) / 13<< "%\n";
				cout << spirals[i] << ": " << n << " " << (double)eqn<< "% at " << n << " " << ((q*4) + 1) << endl;;
			}
		}
	}
	//for(i
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout.precision(20);
	cout << duration << endl;

}
