//Made from Wikipedia's description of the algorithm

#include<iostream>
#include<math.h>
#include<bitset>
#include<ctime>

using namespace std;

int main() {

	clock_t start;
	double duration;
	start = clock();

	const int limit = 10000000;
	const int limsq = sqrt(limit);

	int x, y, yy;

	bitset<limit> p;
	p.set ( );

	for (x = 1; x < limsq; x++) {

		for (y = 1; y < limsq; y++) {

			if (y != x && y != 1 && y % x == 0) {
				yy = y * y;

				while(yy < limit) {

					p.reset(yy);
					yy += y;

				}
			}
		}
	}


	for (y = 0; y < limit; y++) {
		if (p[y] == 1) {
			cout << y << endl;

		}
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << endl << duration << " seconds\n";

}
