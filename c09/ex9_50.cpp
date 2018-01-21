#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<string> vec = {"12", "11", "23", "4.5"};
	double sum = 0;
	for (string s : vec) {
		sum += stod(s);
	}
	cout << sum << endl;
}
