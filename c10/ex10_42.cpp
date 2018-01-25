#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;

void print(list<string> &words) {
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}


void elimDups(list<string> &words) {
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

int main() {
	string word;
	list<string> lst;
   	cout << "input:" << endl;
   	while (cin >> word) {
   		lst.push_back(word);
   	}
   
   	elimDups(lst);
	return 0;
}

