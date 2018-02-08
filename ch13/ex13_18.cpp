#include <iostream>
#include <string>

using namespace::std;

class Employee {
	friend void print(const Employee&);
	public:
		Employee() = default;
		Employee(string name):name(name) {
			static int ids;
			ids++;
			id = ids;
		}
	private:
		string name;
		int id;
};

void print(const Employee &e) {
	cout << "name:" << e.name << " " << "id:" << e.id << endl;
}

int main() {
	Employee e("bob");
	Employee e2("dylan");
	print(e);
	print(e2);
}
