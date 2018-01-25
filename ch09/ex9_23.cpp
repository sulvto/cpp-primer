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
	
	list<int> c = {10};
	if (!c.empty()) {
		auto val1 = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
		cout << "val1:" << val1 << "\n"
			 << "val2:" << val2 << "\n"
			 << "last:" << *last << "\n"
			 << "val3:" << val3 << "\n"
			 << "val4:" << val4 << "\n" 
			 << endl;
	}
}
