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
	words.sort();
	cout << "sort:" << endl;
	print(words);
	words.unique();
	cout << "unique:" << endl;
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

