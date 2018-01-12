#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

void print(const Sales_data &sales) {
	std::cout << sales.bookNo << " " << sales.units_sold << " " << sales.revenue << std::endl;
}

int main() {
	Sales_data item = {"978-0590353403", 25, 15.99};
	print(item);
}
