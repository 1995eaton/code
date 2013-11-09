#include<iostream>
using namespace std;

int main() {

	unsigned int sumSquares = 0;

	for(size_t x = 1; x <= 100; ++x) {
		sumSquares += x * x;
	}

	cout << (5050*5050) - sumSquares << endl;
	return 0;

}
