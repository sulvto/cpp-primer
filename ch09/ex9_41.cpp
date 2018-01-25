#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main() {
	vector<char> vec = {'H', 'e', 'l', 'l', 'o', '.'};
	string s(vec.begin(), vec.end());
	std::cout << s << std::endl;
}
