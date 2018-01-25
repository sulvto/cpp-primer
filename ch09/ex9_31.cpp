#include <iostream>
#include <list>

using std::list;

int main() {
	list<int>	vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if(*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;
		} else {
			iter = vi.erase(iter);
		}
	}

	for (int i : vi) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	return 0;
}
