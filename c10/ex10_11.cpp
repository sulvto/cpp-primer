#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void print(vector<string> &words) {
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}


void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	cout << "sort:" << endl;
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	cout << "unique:" << endl;
	print(words);
	words.erase(end_unique, words.end());
	cout << "erase:" << endl;
	print(words);
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() > s2.size();
}

int main() {
	string word;
	vector<string> vec;
   	cout << "input:" << endl;
   	while (cin >> word) {
   		vec.push_back(word);
   	}
   
   	elimDups(vec);
	stable_sort(vec.begin(), vec.end(), isShorter);
	cout << "stable_sort:" << endl;
	print(vec);
	return 0;
}

