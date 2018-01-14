#include <iostream>
#include <vector>
using std::vector;

bool find(vector<int> &iter, int item) {
	auto begin = iter.begin();
	while (begin != iter.end()) {
		if(*begin == item) {
			return true;
		}
		++begin;
	}

	return false;
}

int main() {
	vector<int> iter = {1, 2, 3, 4, 7, 9};
	std::cout<< "find 8:" << find(iter, 8) << "\nfind 4:" << find(iter, 7) << std::endl;
}
