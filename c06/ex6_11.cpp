#include <iostream>

int reset(int &v) {
    v = 0;
}

int main() {
    int v;
    if (std::cin>> v) {
        reset(v);
        std::cout << v << std::endl;
    }
}
