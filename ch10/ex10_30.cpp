#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;

int main() {
	istream_iterator<int> in(cin), end;
	vector<int> vec;
	copy(in, end, back_inserter(vec));
	sort(vec.begin(), vec.end());
	ostream_iterator<int> out(cout, " ");
	copy(vec.cbegin(), vec.cend(), out);
}
