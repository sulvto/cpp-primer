
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int i;
    while (cin >> i) {
        if (i == 42) {
            cout << "input 42!" << "\n" << endl;
            return 0;
        }
    }
}
