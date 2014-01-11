#include<iostream>

int main() {

	int n, c = 0;
	const int divisorlimit = 500;
	int nat = 1;

	for(int tnum = 1; c <= divisorlimit; tnum += nat) {

		c = 0;

		for(int n = 1; n <= tnum / n; n++) {

			if(tnum % n == 0) {
				c++;

				if(tnum / n != n) {
					c++;
				}

				else {
					break;
				}

			}
		}
		nat++;
		if(c >= divisorlimit) {
			std::cout << tnum << std::endl << c << std::endl << std::endl;
		}

	}

	return 0;

}

