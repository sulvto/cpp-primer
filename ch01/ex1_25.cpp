#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;
    if (std::cin >> total){
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << "total:" << total << std::endl;
                total = trans;
            }
        }
        std::cout << "total:" << total << std::endl;
    } else {
        std::cout << "No data?!" << total << std::endl;
        return -1;
    }
    return 0;
}
