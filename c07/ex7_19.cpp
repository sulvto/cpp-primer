#include <iostream>

struct Parson {
	private:
		std::string name;
		std::string address;

	public:
		Parson() = default;
		Parson(const std::string &s): name(s) {}
		Parson(const std::string &n, const std::string &a): name(n), address(a) {}
		Parson(std::istream &is) {
			is >> name >> address;
		}

		std::string getName() const {
			return name;	
		}
		
		std::string getAddress() const {
			return address;	      
		}
};


int main() {
	Parson parson(std::cin);
	std::cout << "name:" << parson.getName() << " address:" << parson.getAddress() << std::endl;
}
