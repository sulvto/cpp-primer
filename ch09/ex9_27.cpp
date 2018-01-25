#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cin;
using std::cout;
using std::endl;

int main() {
	forward_list<int> flst = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()){
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}

	cout << "output:";
	for (int i : flst) {
		cout << i << " ";
	}
	cout << endl;
}
