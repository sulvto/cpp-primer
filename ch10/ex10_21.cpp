#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	int i = 8;
	auto l = [&]() -> bool 
	{ if (i == 0) return true; else { --i; return false;}};
	while (!l()) {
		cout << "--i" << "\n" ;
	}
	cout << endl;
}
