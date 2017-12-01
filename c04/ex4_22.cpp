
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    int grade;
    while (cin >> grade) {
        cout << ((grade > 90) ? "high pass" : (grade < 60 ) ? "fail" : (grade < 75) ? "low pass" : "pass") << "\n" << endl;
    
        if (grade > 90) {
            cout << "high pass";
        } else if (grade > 74) {
            cout << "pass";
        } else if (grade > 59) {
            cout << "low pass";
        } else {
            cout << "fail";
        }
        cout << endl;

    }
}
