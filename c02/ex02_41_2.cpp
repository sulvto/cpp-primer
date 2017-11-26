#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1,data2;
    double price;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data2.bookNo == data1.bookNo) {
        std::cout << data2.bookNo << " " << data1.units_sold + data2.units_sold << " " << data1.revenue + data2.revenue << std::endl;
    } else {
        std::cout << "Data must refer to the same ISBN" << std::endl;
    }

}
