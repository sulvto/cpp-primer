#include <iostream>

int swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int v1, v2;
    if (std::cin>> v1 >> v2) {
        swap(v1, v2);
        std::cout << v1 <<  "," << v2 << std::endl;
    }
}
