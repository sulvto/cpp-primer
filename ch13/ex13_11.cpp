#include <iostream>
#include <string>

using namespace::std;

class HasPtr {
	friend void print(const HasPtr&);
	public:
		HasPtr(const string &s = string()) :
				ps(new string(s)), i(0) {}
		
		HasPtr(const HasPtr &hp) {
		    ps = new string(*(hp.ps));   	
        	i = hp.i;
		}                         
		
		HasPtr& operator=(const HasPtr&);
		~HasPtr() {
			delete ps;
		}
	private:
		string *ps;
		int i;
};

HasPtr& HasPtr::operator=(const HasPtr &hp) {
	ps =  new string(*(hp.ps));
	i = hp.i;
	return *this;
}

void print(const HasPtr &hp) {
	cout << *(hp.ps) << endl;
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

