#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {


	for(int index = 1; index < argc; ++index) {

		ifstream dictionary("dictionary.txt");
		string line;
		string word_in = argv[index];
		cout << word_in << ":\n";

		while(getline(dictionary, line)) {

			if(line.length() == word_in.length()) {

				string line_sorted = line; sort(line_sorted.begin(), line_sorted.end());
				string word_in_sorted = word_in; sort(word_in_sorted.begin(), word_in_sorted.end());

				if(line_sorted == word_in_sorted) {
					cout << " " << line << endl;
				}
			}
		}
	}

	return 0;
}
