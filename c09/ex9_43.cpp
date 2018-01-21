#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

bool match(string::iterator begin, string::iterator end, const string s) {
	int index = 0;
	auto s_begin = s.begin();
	auto s_end = s.end();
	while (begin != end && s_begin != s_end) {
		if (*s_begin == *begin) {
			++s_begin;
			++begin;
			++index;
		} else {
			begin -= index;
			return false;
		}
	}
	begin -= index;
	return (s_begin == s_end);
}

int fun(string &s, string oldVal, string newVal) {
	auto begin = s.begin();
	int pos = 0;

	while (begin != s.end()) {
		if (match(begin, s.end(), oldVal)) {
			s.erase(pos, oldVal.size());
			s.insert(pos, newVal);
			begin = s.begin() + newVal.size() + pos;
			pos += newVal.size();
		} else {
			++pos;
			++begin;
		}
	}
}



int main() {
	string s("tho, thru");
	fun(s, "tho", "though");
	fun(s, "thru", "through");
	cout << s << endl;
}
