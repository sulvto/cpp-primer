#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

/**
 *
 * 		---------------------------------
 * 		| 0	| 1	| 2	| 3	| 4	|			|
 * 		---------------------------------
 * 		|					|			|
 * 	 elements			first_free     cap
 */
class StrVec {
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}

	StrVec(const StrVec&);

	StrVec &operator=(const StrVec&);

	~StrVec();

	void push_back(const std::string&);

	size_t size() const { return first_free - elements; }

	size_t capacity() const { return cap - elements; }

	std::string *begin() const { return elements; }

	std::string *end() const { return first_free; }

	void resize(size_t s);

    void print();


private:
	std::allocator<std::string> alloc;

	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}

	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);

	void free();

	void reallocate();

	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

StrVec::StrVec(const StrVec &strVec) {
	auto data = alloc_n_copy(strVec.begin(), strVec.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec::~StrVec() {
	free();
}

StrVec &StrVec::operator=(const StrVec &strVec) {
	auto data = alloc_n_copy(strVec.begin(), strVec.end());
	free();
	elements = data.first;
	first_free = cap = data.second;

	return *this;
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::push_back(const std::string &str) {
    chk_n_alloc();
	alloc.construct(first_free++, str);
}

void StrVec::reallocate() {
	auto new_capacity = size() ? size() * 2 : 1;
	resize(new_capacity);
}

void StrVec::resize(size_t s) {
	if (s > capacity()) {
		auto new_data = alloc.allocate(s);
		auto dest = new_data;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i) {
			alloc.construct(dest++, std::move(*elem++));
		}
		free();

		elements = new_data;
		first_free = dest;
		cap = elements + s;
	}
}

void StrVec::print() {

    std::cout << "size: " << size() << " capacity: " << capacity() << " content: ";

    for_each(begin(), end(), [](std::string s) { std::cout << s; });

    std::cout << std::endl;
}


int main() {
	StrVec str;
	str.push_back("a");
    str.print();

	str.push_back("b");
    str.print();

    str.resize(10);
    str.push_back("ccc");
    str.push_back("ddddd");
    str.push_back("ff");
    str.print();

	return 0;
}
