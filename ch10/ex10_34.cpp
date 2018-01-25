#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
	auto rbegin = vec.rbegin();
	auto rend = vec.rend();
	for_each(rbegin, rend, [](int i) { cout << i << " ";});
	cout << endl;
}
