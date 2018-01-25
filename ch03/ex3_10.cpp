#include <string>
#include <iostream>
#include <cctype>


using std::cin;
using std::cout;   
using std::endl;
using std::string;

// g++ ex3_10.cpp -o ex3_10.o -std=c++11
int main() {
    string str;
    decltype(str.size()) a = 0;
    while (getline(cin, str)) {
        string s1 = str;
        for (auto &s: s1) {
            if (ispunct(s)) {
                s = ' ';
            }
        }  
        cout << s1 << endl;

        string s2 = string(str.size(), ' ');
        for (decltype(str.size()) index = 0; index < str.size(); index++) {
            if (ispunct(str[index])) {
                decltype(str.size()) i = index;
                decltype(str.size()) j = index + 1;
                
                for (decltype(str.size()) i = index ; j < str.size() && i < j; j++) {
                    if (!ispunct(str[j])) {
                        s2[i] = str[j];
                        i++;
                    }
                }
                if (j == str.size()) {
                    cout << s2 << endl;
                    break;
                }
            } else {
                s2[index] = str[index];
            }
                
        }

    }


}
