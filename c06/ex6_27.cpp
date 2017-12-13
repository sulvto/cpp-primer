#include <iostream>
using std::initializer_list;

int sum(initializer_list<int> il) {
    int result = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        result += *beg;
    }

    return result;
}

int main(int argc, char **argv) {
    std::cout << "1-5:"  << sum({1, 2, 3, 4, 5}) << "\n";
    std::cout << "6-10:" << sum({6, 7, 8, 9, 10}) << std::endl;
            
    
}
