#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>* foo() {
	return new vector<string>();
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
	vector<string> *vec = foo();
	input(*vec);
	print(*vec);
	delete vec;
}
