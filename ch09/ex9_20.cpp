#include <iostream>
#include <string>
#include <list>
#include <deque>
using std::list;
using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	
	string word;
	list<int> li = {2, 3, 4, 7, 34, 455, 57, 231, 222, 56};
	deque<int> even;
	deque<int> odd;
	
	auto begin = li.begin();
	auto end = li.end();    

	while (begin != end) {
		if (*begin % 2) {
			odd.push_back(*begin);
		} else {
			even.push_back(*begin);
		}

		++begin;
	}
	
	auto e_begin = even.begin();
	auto e_end = even.end();    	
                            
	cout << "even: ";
	while (e_begin != e_end) {
		cout << *e_begin << " ";
		++e_begin;
	}	

	cout << "\n";

	auto o_begin = odd.begin();
	auto o_end = odd.end();    	
	                        
	cout << "odd: ";
	while (o_begin != o_end) {
		cout << *o_begin << " ";
		++o_begin;
	}                               
	cout << endl;
}
