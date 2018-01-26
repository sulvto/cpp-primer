#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
	string word;
	map<string, size_t> word_count;
	while (cin >> word) {
		++word_count[word];
	}

	// print
	for (const auto &wc : word_count) {
		cout << wc.first << " occurs " << wc.second << ((wc.second > 1) ? " times" : " time") << endl;
	}

}
