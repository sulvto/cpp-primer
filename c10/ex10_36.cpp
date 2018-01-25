#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {1, 2, 0, 4, 5, 6, 0, 8};
	auto rbegin = vec.rbegin();
	auto rend = vec.rend();
	auto f = find(rbegin, rend, 0);
	while (f != (vec.rbegin() - 1)) {
		cout << *f << " ";
		--f;
	}

	cout << endl;
}
