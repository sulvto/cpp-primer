#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void add(vector<string> &vec, string s) {
	auto f = find(vec.cbegin(), vec.cend(), s);
	if (f == vec.cend()) {
		vec.push_back(s);
	}
}


int main() {
	string word;
	vector<string> vec;
   	while (cin >> word)	{
		add(vec, word);
		for_each(vec.cbegin(), vec.cend(), [](const string &s) { cout << s << " "; });
		cout << endl;
	}
}
