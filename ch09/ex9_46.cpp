#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string fun(string name, string prefix, string suffix) {
	name.insert(0, prefix);
	name.insert(name.size(), suffix);
	return name;
}


int main() {
	string name("Dylan");
	name = fun(name, "Mr.", "!!!");
	cout << name << endl;
}
