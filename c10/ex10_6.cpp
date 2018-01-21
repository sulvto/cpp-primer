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
   	cout << "input:" << endl;
   	while (cin >> i) {
   		vec.push_back(i);
   	}
   
   	fill_n(vec.begin(), vec.size(), 0);
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

