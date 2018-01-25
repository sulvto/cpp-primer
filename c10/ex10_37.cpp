#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto rbegin = vec.rbegin();
	auto rend = vec.rend();
	rbegin += 3;
	rend -= 4;

	list<int> lst;
	copy(rbegin, rend, back_inserter(lst));
	for_each(lst.cbegin(), lst.cend(), [](int i){ cout << i << " "; });
	cout << endl;
}
