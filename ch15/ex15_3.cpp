#include <iostream>

class Quote {
    public:
        Quote() = default;
        Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) { }
        std::string isbn() const { return bookNo; }
        virtual double net_price(std::size_t n) const {
            return n * price;
        }

		double printe_total(std::ostream &os, const Quote &item, size_t n)  {
			double ret = item.net_price(n);
			os << "ISON: " << item.isbn() << " total due: " << ret << std::endl;

			return ret;
		}

        virtual ~Quote() = default;

    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

int main() {
	// TODO


}
