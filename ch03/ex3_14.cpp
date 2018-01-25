#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int number;
    vector<int> numbers;
    while (cin >> number ) {
        numbers.push_back(number);
        for (auto n: numbers) {
            cout << n << " ";
        }
        cout << endl;
    }
}


