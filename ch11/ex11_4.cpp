#include <iostream>
#include <string>
#include <map>
#include <cctype>  
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
	string word;
	map<string, size_t> word_count;
	while (cin >> word) {
    	transform(word.begin(), word.end(), word.begin(), tolower);  
		string newWord;
		remove_copy_if(word.begin(), word.end(), back_inserter(newWord), ispunct);
		++word_count[newWord];
	}

	// print
	for (const auto &wc : word_count) {
		cout << wc.first << " occurs " << wc.second << ((wc.second > 1) ? " times" : " time") << endl;
	}

}
