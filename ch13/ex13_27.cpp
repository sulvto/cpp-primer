#include <iostream>
#include <string>

using namespace::std;

class HasPtr {
	friend void print(const HasPtr&);
	public:
		HasPtr(const string &s = string()) :
				ps(new string(s)), i(0),use(new size_t(1)) {}
		
		HasPtr(const HasPtr &hp): ps(new string(*(hp.ps))), i(hp.i), use(hp.use) {
			++(*use);
		}                         
		
		HasPtr& operator=(const HasPtr&);
		~HasPtr() {
			--(*use);
			if (*use == 0) {
				delete ps;
				delete use;
			}
		}
	private:
		string *ps;
		int i;
		size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &hp) {
	auto new_s =  new string(*(hp.ps));
	++(*hp.use);
	if (--(*use) == 0) {
		delete ps;
		delete use;
	}
	ps = new_s;
	i = hp.i;
	use = hp.use;
	return *this;
}

void print(const HasPtr &hp) {
	cout << *(hp.ps) << " use:" << *(hp.use) << endl;
}


int main() {
	HasPtr hp("hello world");
	HasPtr hp2 = hp;
	HasPtr hp3("hw");
	hp = hp3;
	print(hp);
	print(hp2);
	print(hp3);
}

