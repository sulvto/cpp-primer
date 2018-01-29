#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class StrBlob {
	public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		StrBlob(initializer_list<string> il);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		void push_back(const string &s) { data->push_back(s); }
		void pop_back();

		string& front();
		string& back();
		string& front() const;
		string& back() const; 	
	
	private:
		shared_ptr<vector<string>> data;
		void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}


string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


int main() {
	StrBlob b1;
	{
		StrBlob b2 = {"a", "b", "c", "d"};
		b1 = b2;
		b2.push_back("e");
		const StrBlob b3 = b2;
	}
	cout << b1.size() << endl;
}
