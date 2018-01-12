#include <iostream>

class NoDefault {
    NoDefault(int){}
};

class C {
  public:
    C() = default;
    C(NoDefault noDef): noDefault(noDef) {};
  private:
        NoDefault noDefault;
};

int main() {

}
