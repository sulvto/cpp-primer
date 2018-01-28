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
using std::multimap;

int main() {
	string word;
	multimap<string, vector<string>> family;
	family.insert({"a", {"aa", "ab"}});
	family.insert({"b", {"ba"}});
	cout << "size:" << family.size() << endl;
	for (const auto &f : family) {
		cout << f.first << " : ";
		for_each(f.second.cbegin(), f.second.cend(), [](const string &s){ cout << s << " ";});
		cout << endl;
	}
}
