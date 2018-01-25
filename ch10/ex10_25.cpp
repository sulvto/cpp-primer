#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
		return s.size() <= sz;
}

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

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	for_each(wc, words.end(), [](const string &s) { cout << s << " ";});
	cout << endl;
}

int main() {
	string word;
	vector<string> vec;
   	cout << "input:" << endl;
   	while (cin >> word) {
   		vec.push_back(word);
   	}
   
   	biggies(vec, 4);
	return 0;
}

