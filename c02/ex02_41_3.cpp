#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data total;
    
    if (std::cin >> total.bookNo) {
        double price;
        std::cin >> total.units_sold >> price;
        total.revenue = total.units_sold * price;
        
        Sales_data trans;
        while (std::cin >> trans.bookNo) {
            std::cin >> trans.units_sold >> price;
            trans.revenue = trans.units_sold * price;
            
            if (total.bookNo == trans.bookNo) {
                total.revenue += trans.revenue;
            } else {
                std::cout << "total: " << total.bookNo << " " << total.units_sold + total.units_sold << " " << total.revenue + total.revenue << std::endl;
                total = trans;
            }
        }    
    } else {
        std::cout << "No data?!" << std::endl;    
        return -1;
    }
    return 0;
}
