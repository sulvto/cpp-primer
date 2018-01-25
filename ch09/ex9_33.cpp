#include <iostream>
#include <vector>

using std::vector;

int main() {
	vector<int>	vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if(*iter % 2) {
			vi.insert(iter, *iter);
			iter += 2;
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
