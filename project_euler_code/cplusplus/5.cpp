#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int main() {

	clock_t start_time = clock();
	vector<int> checkthese = {17, 19, 13, 11, 16, 14, 18};
	int x = 2520;

	while(true) {
		bool nope = 0;
		for(size_t xx = 0; xx < checkthese.size(); ++xx) {
			if(x % checkthese[xx] != 0){nope = 1; break;}
		}
		if(nope == 0){
			cout << x << "\nFinished in " << (clock() - start_time) / (double) CLOCKS_PER_SEC << endl;
			return 0;
		}
		x+=2520;
	}

}
