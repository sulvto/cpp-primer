#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
	return s.size() <= sz;
}

int main() {
	cout << "input string:" << endl;
	string word;
	if (cin >> word) {
		int i;
		vector<int> vec;
		cout << "input vector:" << endl;
		while (cin >> i) {
			vec.push_back(i);
		}
		auto iter = find_if(vec.begin(), vec.end(), bind(check_size, word, _1));
		cout << "output: " << *iter << endl;
	}
}
