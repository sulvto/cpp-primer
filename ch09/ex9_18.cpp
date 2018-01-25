#include <iostream>
#include <string>
#include <deque>
using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	
	string word;
	deque<string> deq;
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
