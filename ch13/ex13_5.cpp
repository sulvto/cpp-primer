#include <iostream>
#include <string>

using namespace::std;

class HasPtr {
	public:
		HasPtr(const string &s = string()) :
				ps(new string(s)), i(0) {}
		HasPtr(const HasPtr &hp): ps(hp.ps), i(hp.i) {}
	private:
		string *ps;
		int i;
};

int main() {}
