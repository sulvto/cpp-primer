#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main() {
	string word;
	unordered_map<string, size_t> word_count;
	while (cin >> word) {
		++word_count[word];
	}

	// print
	for (const auto &wc : word_count) {
		cout << wc.first << " occurs " << wc.second << ((wc.second > 1) ? " times" : " time") << endl;
	}

}
