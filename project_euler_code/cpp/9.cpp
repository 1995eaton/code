#include<iostream>

using namespace std;

int main() {

	int a, b, c;

	for(c = 0; true; ++c) {
		for(b = 0; b < c; ++b) {
			for(a = 0; a < b; ++a) {
				if(a*a + b*b == c*c && a + b + c == 1000) {
					cout << a*b*c << endl;
					return 0;
				}
			}
		}
	}
}
