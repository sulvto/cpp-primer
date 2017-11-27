#include <string>
#include <iostream>
#include <cctype>


using std::cin;
using std::cout;   
using std::endl;
using std::string;

// g++ ex3_6.cpp -o ex3_8.o -std=c++11
int main() {
    string str;
    decltype(str.size()) a = 0;
    while (getline(cin, str)) {

        string s1 = str;
        for (decltype(s1.size()) index = 0; index < s1.size(); index++) {
            if (!isspace(s1[index])) {
                s1[index] = 'X';
            }
        }      
        cout << s1 << endl;

        string s2 = str;
        decltype(s2.size()) index = 0;
        while (index < s2.size()) {
            if (!isspace(s2[index])) {
                s2[index] = 'X';
            }
            index++;
        }
        cout << s2 << endl;
    }


}
