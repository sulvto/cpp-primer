#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec;
	list<int> lst;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	for (int i : ia) {
		vec.push_back(i);
		lst.push_back(i);
	}

	auto v_begin = vec.begin();
	while (v_begin != vec.end()) {
		if (*v_begin % 2) {
			v_begin = vec.erase(v_begin);
		} else {
			++v_begin;
		}
	}

	auto l_begin = lst.begin();
    while (l_begin != lst.end()) {
    	if (*l_begin % 2) {
    		++l_begin;
    	} else {
    		l_begin = lst.erase(l_begin);
    	}
    }

	cout << "vec:";
	for (int i : vec) {
		cout << i << " ";
	}
	cout << "\n" 
		 << "lst:";
	for (int i : lst) {
		cout << i << " ";
	}
	cout << endl;
}
