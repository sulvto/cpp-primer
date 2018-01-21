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
	
	cout << "accumulate: " << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
}
