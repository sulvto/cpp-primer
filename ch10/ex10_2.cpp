#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string s;
	vector<string> vec;
	cout << "input:" << "\n";
	while (cin >> s) {
		cout << "count: " << count(vec.begin(), vec.end(), s) << "\n";
		vec.push_back(s);
		cout << "input:" << endl;
	}
}
