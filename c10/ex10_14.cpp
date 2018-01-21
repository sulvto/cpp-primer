#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	auto lmd = [](int a, int b) { return a + b;};
	cout << lmd(2, 3) << endl;
	return 0;
}

