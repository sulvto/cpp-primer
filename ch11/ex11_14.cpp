#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

int main() {
	string word;
	map<string, vector<pair<string, string>>> family;
	family["a"].push_back({"aa", "123"});
	family["a"].push_back({"ab", "234"});
	family["b"].push_back({"ba", "345"});
	cout << "size:" << family.size() << endl;
	for (const auto &f : family) {
		cout << f.first << " : ";
		for_each(f.second.cbegin(), f.second.cend(), [](const pair<string, string> &p){ cout << "<" << p.first << " - " << p.second << "> ";});
		cout << endl;
	}
}
