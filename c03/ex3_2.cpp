#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string str;
    string tmp;
    while (getline(cin, str)) {
        for (int i=0; i<str.size(); i++) {
            if(str[i] == ' ') {
                cout << tmp << endl;
                tmp = "";
                break;
            } else {
                tmp += str[i];
            }
        }
        if (tmp.size() > 0) {
            cout << tmp << endl;
            tmp = "";
        }
    }
        
    return 0;
}

