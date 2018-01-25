#include <iostream>
#include <string>
using std::string;

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(int argc, char **argv) {
    string s1 = "aaa";
    string s2 = "aa";
    std::cout << isShorter(s1, s2) << std::endl;
}
