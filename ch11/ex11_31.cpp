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
using std::multimap;
using std::pair;

int main() {
	string word;
	multimap<string, string> map;
	map.insert({"a", "aa"});
	map.insert({"b", "bb"});
	if (map.find("a") != map.end()) {
		map.erase("a");
	}

	for_each(map.cbegin(), map.cend(), [](const pair<string, string> &p) { cout << "<" << p.first << ":" << p.second << ">"; });
	cout << endl;
	if (map.find("c") != map.end()) {
		map.erase("c");              
	}
	for_each(map.cbegin(), map.cend(), [](const pair<string, string> &p) { cout << "<" << p.first << ":" << p.second << ">"; });
	cout << endl;
}
