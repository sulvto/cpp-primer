#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	int i;
	vector<int> vec;
	cout << "input:" << "\n";
	while (cin >> i) {
		cout << "count: " << count(vec.begin(), vec.end(), i) << "\n";
		vec.push_back(i);
		cout << "input:" << endl;
	}
}
