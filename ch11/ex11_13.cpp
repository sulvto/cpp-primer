#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

int main() {
	string s;
	int i;
	vector<pair<string, int>> vec;
   	while (cin >> s)	{
		if(cin >> i) { 
			// vec.push_back({s, i});
			// vec.push_back(pair<string, int>(s, i));
			vec.push_back(make_pair(s, i));
		}
		for_each(vec.cbegin(), vec.cend(), [](const pair<string, int> &p) { cout << p.first << " " << p.second << " | "; });
		cout << endl;
	}
}
