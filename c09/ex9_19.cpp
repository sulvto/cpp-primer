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
	list<string> deq;
	while (cin >> word) {
		cout << "push:" << word << "\n" << endl;
		deq.push_back(word);
	}
	
	cout << "output: ";
	auto begin = deq.begin();
	auto end = deq.end();
	while (begin != end) {
		cout << *begin << " ";
		++begin;
	}
	cout << endl;
}
