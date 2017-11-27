#include <string>
#include <iostream>
#include <cctype>


using std::cin;
using std::cout;   
using std::endl;
using std::string;

// g++ ex3_6.cpp -o ex3_6.o -std=c++11
int main() {
    string str;
    decltype(str.size()) a = 0;
    while (getline(cin, str)) {
        for (auto &s: str) {
            if (!isspace(s)) {
                s = 'X';
            }
        }  
        cout << str << endl;
    }


}
