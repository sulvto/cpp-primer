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

	private:
		string *ps;
		int i;
};

void print(const HasPtr &hp) {
	cout << *(hp.ps) << endl;
}

HasPtr& HasPtr::operator=(const HasPtr &hp) {
	ps =  new string(*(hp.ps));
	i = hp.i;
	return *this;
}

int main() {
}

