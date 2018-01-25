
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string s = "word";
    string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");

    cout << p1 << "\n" << endl;
    
}
