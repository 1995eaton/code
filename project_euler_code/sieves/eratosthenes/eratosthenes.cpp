//Made from Wikipedia's description of the algorithm

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<ctime>

using std::cout; using std::endl;

int main(int argc, const char* argv[]) {

	std::ofstream primes;
	primes.open(argv[2]);

	clock_t start;
	double duration;
	start = clock();

	unsigned int limit = (int)strtoul(argv[1], 0, 0);
	const int limsq = sqrt(limit);

	int x, xx;

	std::vector<bool>& p = *(new std::vector<bool>(limit));

	for (x = 2; x < limsq; x++) {
		if(p[x] == 0) {
			xx = x * x;
			while(xx < limit) {
				//p.set(xx);
				p[xx] = 1;
				xx += x;
			}
		}
	}

	for (x = 2; x < limit; x++) {if (p[x] == 0) {primes << x << endl;}}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout.precision(20);
	primes << duration << endl;
	primes.close();

}
