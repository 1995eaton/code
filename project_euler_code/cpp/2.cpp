#include <iostream>

using namespace std;

int main()	{

	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int limit = 4000000;
	int sum = 0;
	cout << endl;


	while (true) {
		a += b;
		b += a;
		if (a % 2 == 0 and a < limit) {
			sum += a;
			cout << a << " + sum == " << sum << endl; }
		else if (b % 2 == 0 and b < limit) {
			sum += b;
			cout << b << " + sum == " << sum << endl; }
		else if (a >= limit or b >= limit) {
			break;
		}

	}

	cout << endl << "The total value is: " << sum << endl << endl;

	return 0;
}
