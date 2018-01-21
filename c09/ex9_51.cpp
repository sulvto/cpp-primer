#include <iostream>
#include <string>
#include <stdexcept>

using std::runtime_error;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class date {
	public:
		date(string date_str) {
			int pos = 0;
			int length = 0;
			int index = 0;
			int arr_index = 0;
			auto begin = date_str.begin();
			while (begin != date_str.end()) {
				if (*begin == ' ' || *begin == ',' || *begin == '/') {
					if (arr_index == 0) {
						string m_str = date_str.substr(pos, length - pos);
						if (m_str.find_first_of("0123456789") != string::npos) {	
							month = stoi(m_str);
						} else {
							if (m_str == "January" || m_str == "Jan") {
								month = 1;
							} 
							// ...
							else {
								throw runtime_error("Date format error.");
							}

						}
					} else {
						day = stoi(date_str.substr(pos, length - pos));
					}
					++arr_index;
					pos = index+1;
				}
				++begin;
				++length;
				++index;
			}

			year = stoi(date_str.substr(pos, length - pos));
		}

		void print() const {
			cout << year << "-" << month << "-" << day << endl;
		}
	private:
		unsigned year;
		unsigned month;
		unsigned day;
};

int main() {
	date d("1/1/1990");
	d.print();
	d = date("1 3,1996");
	d.print();
	d = date("5/1,1930");
	d.print();
	d = date("Jan/3/1992");
	d.print();

}

