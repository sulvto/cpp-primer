#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string str;
    vector<string> v;
    while (cin >> str) {
        v.push_back(str);
        for (auto s: v) {
            cout << s << " ";
        }
        cout << endl;
    }
}


