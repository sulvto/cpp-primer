#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include "string.h"

/**
 *
 *
 */
class String {
public:
	String(const char *str);

    String() : buf(nullptr), len(0), cap(0) { }

    String(const String &);

    String &operator=(const String &);

    ~String();

    void append(const char *str);

    const char* content() const { return buf; }

    size_t size() const { return len; }

    size_t capacity() const { return cap; }

    void resize(size_t);

private:
    std::allocator <char> alloc;

    char *alloc_n_copy(const char*, const size_t len);

    void free();

    size_t len;
    size_t cap;
    char *buf;
};

char *String::alloc_n_copy(const char *str, const size_t len) {
    char *new_data = alloc.allocate(len);
    std::uninitialized_copy_n(str, len, new_data);

    return new_data;
}

void String::resize(size_t s) {
    std::cout << "resize: " << s << std::endl;
    if (s > cap) {
        char *new_data = alloc_n_copy(buf, s);
        free();
        buf = new_data;
        cap = s;
    }
}

void String::free() {
    if (len > 0) {
        alloc.destroy(buf);
        alloc.deallocate(buf, len);
    }
}

String::String(const char *str) {
    len = cap = strlen(str);
    buf = alloc_n_copy(str, len);
}

String::String(const String &str) {
    buf = alloc_n_copy(str.buf, str.len);
    len = cap = str.len;
}

String& String::operator=(const String &str) {
    char* new_data = alloc_n_copy(str.buf, str.len);

    free();
    buf = new_data;
    len = str.len;
    cap = str.cap;

    return *this;
}

String::~String() {
    free();
}

void String::append(const char *str) {
    int append_len = strlen(str);

    if (cap - len < append_len) {
        int capX2 = cap * 2;
        int length = append_len + len;

        resize(capX2 > length ? capX2 : length);
    }

    char *p = buf;
    for (int i = 0; i < len ; i++) {
        p++;
    }

    for (int i = 0; i < append_len ; i++) {
        *p = *str;
        p++, str++;
    }

    len += append_len;
}

void print(const String &s) {
    std::cout << "length: " << s.size() << ", capacity: " << s.capacity() << ", content: " << s.content() << std::endl;
}


int main() {
    String s("a");
    print(s);
    s.append("bbb");
    print(s);

    String s1 = s;
    s1.append("c");
    print(s);
    print(s1);

    s = s1;
    print(s);
}