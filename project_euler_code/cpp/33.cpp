#include<iostream>
#include<ctime>

using namespace std;

int gcd(int n, int d) {
	if(n % d != 0)
		gcd(n, n % d);
	return n;
}

int main() {

	clock_t start = clock();
	unsigned long den = 1; unsigned long num = 1;

	for(size_t x = 10; x < 99; ++x) {
		for(size_t xx = 10; xx < x; ++xx) {
			if(x % 10 != 0 && (double)xx / x == (((double)xx - (xx % 10)) / 10) / (x % 10) && (x - (x % 10)) / 10 == xx % 10) {
				//den *= x / gcd(x, xx);
				//num *= xx / gcd(x, xx);
				den *= x;
				num *= xx;
			}
		}
	}

	cout << den / gcd(num, den) << endl;
	//cout << gcd(num, den) << endl;
	cout << (clock() - start) / (double)CLOCKS_PER_SEC << endl;

	return 0;

}
