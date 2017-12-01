#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    
    cout << " v1:" << v1.size();
    cout << " v2:" << v2.size();
    cout << " v3:" << v3.size();
    cout << " v4:" << v4.size();
    cout << " v5:" << v5.size();
    cout << " v6:" << v6.size();
    cout << " v7:" << v7.size();
    cout << endl;
}


