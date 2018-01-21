#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int i = 4;
	auto lmd = [i](int a) { return a + i;};
	cout << lmd(3) << endl;
	return 0;
}

