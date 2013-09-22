#include<iostream>

using namespace std;

int main() {

	int trianglenumber;
	const int divisorlimit = 500;
	int n;
	int natural = 1;
	int c = 0;

	for(trianglenumber = 1; c <= divisorlimit; trianglenumber += natural) {

		c = 0;

		for(n = 1; n <= trianglenumber / n; n++) {

			if(trianglenumber % n == 0) {
				c++;

				if(trianglenumber / n != n) {
					c++;
				}

				else {
					break;
				}

			}
		}

		natural++;

		if(c >= divisorlimit) {
			cout << trianglenumber << endl << c << endl << endl;
		}

	}

	return 0;

}

