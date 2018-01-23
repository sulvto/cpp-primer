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
	string word;
	vector<string> vec;
	cout << "input:" << "\n";
	while (cin >> word) {
		vec.push_back(word);
	}

	
	cout << "count: " << count_if(vec.begin(), vec.end(), bind(check_size, _1, 6)) << endl;

}
