#include <iostream>
	
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

double Sales_data::avg_price() const {
	if(units_sold) {
		return revenue/units_sold;
	} else {
		return 0;	
	}
}
Sales_data& Sales_data::combine(const Sales_data &sales) {
	units_sold += sales.units_sold;
	revenue += sales.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &sales) {
	double price = 0.0;
	is >> sales.bookNo >> sales.units_sold >> price;
	sales.revenue = sales.units_sold * price;
	return is;	
}

std::ostream &print(std::ostream &os, const Sales_data &sales) {
	os << sales.bookNo << " " << sales.units_sold << " " << sales.revenue << " " << sales.avg_price();
	return os;
}

int main() {
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
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
