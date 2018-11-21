#include <iostream>
	
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;

class Sales_data {
	friend istream &read(istream &is, Sales_data &sales);
	friend ostream &print(ostream &os, const Sales_data &sales);
	friend ostream &operator<<(ostream &os, const Sales_data &item);
	friend istream &operator>>(istream &is, Sales_data &item);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

	public:
		Sales_data() = default;
		Sales_data(const std::string &s): bookNo(s) {}
		Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) {}
		Sales_data(std::istream &is);

		std::string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&);
		inline double avg_price() const;
		
		Sales_data &operator+=(const Sales_data &rhs);
		

	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};


istream &read(istream &is, Sales_data &sales) {
	double price = 0.0;
	is >> sales.bookNo >> sales.units_sold >> price;
	sales.revenue = sales.units_sold * price;
	return is;	
}

ostream &print(ostream &os, const Sales_data &sales) {
	os << sales.bookNo << " " << sales.units_sold << " " << sales.revenue << " " << sales.avg_price();
	return os;
}

Sales_data::Sales_data(istream &is) {
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

ostream &operator<<(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();

	return os;
}

istream &operator>>(istream &is, Sales_data &item) {
	double price;

	is >> item.bookNo >> item.units_sold >> price;

	if (is) {
		item.revenue = item.units_sold * price;
	} else {
		item = Sales_data();
	}

	return is;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum += rhs;

	return sum;
}

int main() {
	Sales_data data(cin);
	print(cout, data) << endl;
	return 0;
}
