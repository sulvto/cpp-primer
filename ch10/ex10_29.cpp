#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::endl;


int main() {
	ifstream in("ex10_1.cpp");
	istream_iterator<string> str_it(in);
	istream_iterator<string> eof;
	vector<string> vec;
	copy(str_it, eof, back_inserter(vec));

	ostream_iterator<string> out(cout, "\n");
	copy(vec.cbegin(), vec.cend(), out);
	cout << endl;
}
