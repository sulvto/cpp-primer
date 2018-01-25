#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string word;
	vector<string> vec;
	cout << "input:" << "\n";
	while (cin >> word) {
		vec.push_back(word);
	}

	cout << "count: " << count_if(vec.begin(), vec.end(), [](const string &s) { return s.size() > 6;}) << endl;

}
