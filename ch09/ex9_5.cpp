#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

vector<int>::iterator find(vector<int> &iter, int item) {
	auto begin = iter.begin();
	while (begin != iter.end()) {
		if(*begin == item) {
			return begin;
		}
		++begin;
	}

	return begin;
}

int main() {
	vector<int> iter = {1, 2, 3, 4, 7, 9};
	vector<int>::iterator find8 = find(iter, 8);
	vector<int>::iterator find4 = find(iter, 4);

	cout << "find 8:";
	if (find8 == iter.end()) {
		cout << "null";
	} else {
		cout << *find8;
	}

	cout << "\nfind 4:";
	if (find4 == iter.end()) {
		cout << "null";
	} else {
		cout << *find4;
	}
   	cout << endl;
	return 0;
}

