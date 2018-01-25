#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	
	vector<int> c = {10};
	if (!c.empty()) {
		auto begin = *c.begin(), front = c.front();
		auto at0 = c.at(0);
		auto index0 = c[0];
		cout << "at0:" << at0 << "\n"
			 << "index0:" << index0 << "\n"
			 << "begin:" << begin << "\n"
			 << "front:" << front << "\n"
			 << endl;
	}
}
