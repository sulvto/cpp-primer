#include <iostream>
#include <string>

using namespace ::std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);

    friend void print(const HasPtr &);

public:
    HasPtr(const string &s = string()) :
            ps(new string(s)), i(0), use(new size_t(1)) { }

    HasPtr(const HasPtr &hp) : ps(new string(*(hp.ps))), i(hp.i), use(hp.use) {
        ++(*use);
    }

    HasPtr &operator=(HasPtr);

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

HasPtr &HasPtr::operator=(HasPtr hp) {
    swap(*this, hp);
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
    cout << *(rhs.ps) << " swap." << endl;
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

