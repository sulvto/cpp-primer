#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

shared_ptr<vector<string>> foo() {
	return make_shared<vector<string>>();
}

void input(vector<string> &vec) {
	string word;
	if (cin >> word) {
		vec.push_back(word);
	}
}

void print(vector<string> &vec) {
	for_each(vec.cbegin(), vec.cend(), [](const string &s) { cout << s << " ";});
	cout << endl;
}

int main() {
	shared_ptr<vector<string>> vec = foo();
	input(*vec);
	print(*vec);
}
