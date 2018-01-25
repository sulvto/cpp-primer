#include <iostream>

int main() {
    
    int v=50;
    int sum = 0;
    while (v < 100) {
        sum += v++;
    }

    std::cout << sum << std::endl;        
    return 0;
}
