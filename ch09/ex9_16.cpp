#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
using std::cout;
using std::endl;

bool equals(list<int> list, vector<int> vec) {
	if (list.size() == vec.size()) {
		auto lbegin = list.begin();
		auto lend = list.end();
		auto vbegin = vec.begin();
		auto vend = vec.end();

		while (lbegin != lend) {
			if (*lbegin != *vbegin) return false;
			++lbegin;
			++vbegin;
		}

		return true;
	}
	return false;
}

int main() {
	list<int> l = {1, 2, 5, 7, 9};
	vector<int> v = {1, 2, 5, 7, 9};
	vector<int> v2 = {1, 2, 5, 7};
	cout << "eq:" << equals(l, v);
	cout << "\n";
   	cout << "neq:" << equals(l, v2);
	cout << endl;
}


