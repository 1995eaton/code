
#include<iostream>

using namespace std;

int main() {

	int x;
	int sum = 0;
	cout << endl;

	for (x = 0; x < 1000; x++) {

		if (x % 3 == 0 or x % 5 == 0) {
			cout << x << endl;
			sum += x;
		}

	}

	cout << endl << "The total value is: " << sum << endl << endl;

}
