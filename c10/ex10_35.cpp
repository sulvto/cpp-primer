#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
	auto begin = vec.begin();
	--begin;
	auto end = vec.end();
	while (--end != begin) {
		cout << *end << " ";
	}
	cout << endl;
}
