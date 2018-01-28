#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main() {
	string s;
	int i;
	vector<pair<string, int>> vec;
   	while (cin >> s) {
		if(cin >> i) {
			vec.push_back(make_pair(s, i));
		}
		for_each(vec.cbegin(), vec.cend(), [](const pair &p) { cout << p.first << " " << p.second << " | "; });
		cout << endl;
	}
}
