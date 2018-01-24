#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::endl;

void foo(string in_fn, string out_fn1, string out_fn2) {
	ifstream in(in_fn);
	istream_iterator<int> int_it(in), end;

	ofstream out_f1(out_fn1);
	ofstream out_f2(out_fn2);

	ostream_iterator<int> out1(out_f1, " ");
	ostream_iterator<int> out2(out_f2, "\n");

	// output file
	for_each(int_it, end, [&out1, &out2](const int i) { (i%2==0) ? (*out2++ = i) : (*out1++ = i); });
}

int main() {
	foo("ex10_33.txt", "ex10_33_1.txt", "ex10_33_2.txt");
}
