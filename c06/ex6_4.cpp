#include <iostream>
#include <string>


int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

void fun() {
    int input;
    while (std::cin >> input) {
        std::cout << "output:" << fact(input) << std::endl;
    } 
}

int main() {
    fun();
    return 0;
}
