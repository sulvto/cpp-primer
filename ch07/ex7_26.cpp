#include <iostream>
	
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &sales);
	friend std::ostream &print(std::ostream &os, const Sales_data &sales);

	public:
		Sales_data() = default;
		Sales_data(const std::string &s): bookNo(s) {}
		Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) {}
		Sales_data(std::istream &is);

		std::string isbn() const { return bookNo; }
		Sales_data& combine(const Sales_data&);
		inline double avg_price() const;

	private:
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
	os << sales.bookNo << " " << sales.units_sold << " " << sales.revenue << " " << sales.avg_price();
	return os;
}

Sales_data::Sales_data(std::istream &is) {
	read(is, *this);
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
	} else {
		return 0;	
	}
}

Sales_data& Sales_data::combine(const Sales_data &sales) {
	units_sold += sales.units_sold;
	revenue += sales.revenue;
	return *this;
}

int main() {
	Sales_data data(cin);
	print(cout, data) << endl;	
	return 0;
}
