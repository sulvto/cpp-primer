#include <iostream>
#include <string>
#include <list>
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	
	string word;
	list<string> li;
	while (cin >> word) {
		cout << "push:" << word << "\n" << endl;
		li.push_back(word);
	}
	
	cout << "output: ";
	auto begin = li.begin();
	auto end = li.end();
	while (begin != end) {
		cout << *begin << " ";
		++begin;
	}
	cout << endl;
}
