#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {1, 2, 3, 5, 5, 8, 4, 6, 2, 5, 8};
	list<int> lst;
	sort(vec.begin(), vec.end());
	unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));
	for_each(lst.cbegin(), lst.cend(), [](int i){ cout << i << " ";});
	cout << endl;              
}
