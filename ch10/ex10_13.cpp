#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void print(vector<string> &words) {
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}

bool ge5(const string &s) {
	return s.size() >= 5;
}

int main() {
	string word;
	vector<string> vec;
   	cout << "input:" << endl;
   	while (cin >> word) {
   		vec.push_back(word);
   	}
  
   	auto iter = partition(vec.begin(), vec.end(), ge5);
	auto begin = vec.begin();
	while (begin != iter) {
		cout << *begin << " ";
		++begin;
	}
	cout << endl;
	return 0;
}

