#include <iostream>
using std::initializer_list;

typedef int (&arrRef)[5];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};

arrRef arrPtr(int i) {
    return (i % 2) ? odd : even;
}

int main(int argc, char **argv) {
    int (&o)[5] = arrPtr(1);
    int (&e)[5] = arrPtr(2);
    std::cout << o[0] << "\n" << e[0] << std::endl;
}
