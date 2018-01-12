#include <iostream>

std::istream &print(std::istream &is) {
	std::string word;
	while (!is.eof()) {
		is >> word;
		std::cout << word << std::endl;
	}
	is.clear();
	return is;
}

int main() {

}
