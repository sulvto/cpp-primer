#include <iostream>
	
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &sales) {
	double price = 0.0;
	is >> sales.bookNo >> sales.units_sold >> price;
	sales.revenue = sales.units_sold * price;
	return is;	
}

std::ostream &print(std::ostream &os, const Sales_data &sales) {
	double avg_price = 0.0;
	if (sales.units_sold) {
		avg_price = sales.revenue / sales.units_sold;
	}

	os << sales.bookNo << " " << sales.units_sold << " " << sales.revenue << " " << avg_price;
	return os;
}

// g++ ex7_1.cpp -o ex7_1.o -std=c++11
int main() {
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;	
	} else {
			cerr << "No data?!" << endl;
	}
	return 0;
}
