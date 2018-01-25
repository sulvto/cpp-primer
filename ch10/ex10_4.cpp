#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<double> vec = {1.1, 2.4, 1.9};
	cout << "accumulate: " << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl;
}
