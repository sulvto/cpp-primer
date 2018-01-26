#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

int main() {
	string word;
	map<string, vector<string>> family;
	family["a"].push_back("aa");
	family["a"].push_back("ab");
	family["b"].push_back("ba");
	cout << "size:" << family.size() << endl;
	for (const auto &f : family) {
		cout << f.first << " : ";
		for_each(f.second.cbegin(), f.second.cend(), [](const string &s){ cout << s << " ";});
		cout << endl;
	}
}
