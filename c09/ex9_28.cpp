#include <iostream>
#include <forward_list>
#include <string>

using std::string;
using std::forward_list;
using std::cin;
using std::cout;
using std::endl;

void insert(forward_list<string> &flst, string find, string insert) {
	auto curr = flst.begin();
	auto prev = curr;
	while (curr != flst.end()){
		prev = curr;
		if (*curr == find) {
			flst.insert_after(curr, insert);
			return;
		} else {
			++curr;
		}
	}
	flst.insert_after(prev, insert);
}

int main() {
	forward_list<string> flst = {"insert"};
	insert(flst, "insert", "insert1");
	cout << "insert(flst, \"insert\", \"insert1\");"
		 << "\nflst:";
	for (string s : flst) {
		cout << s << " ";
	}

	insert(flst, "insert2", "insert2");
	cout << "\n" 
		 << "insert(flst, \"insert2\", \"insert2\");"
		 << "\nflit:";
	for (string s : flst) {
		cout << s << " ";
	}

	insert(flst, "insert", "--");
	cout << "\n" 
		 << "insert(flst, \"insert\", \"--\"); "
		 << "\nflst:";
	for (string s : flst) {
		cout << s << " ";
	}                                  
	cout << endl;
}
