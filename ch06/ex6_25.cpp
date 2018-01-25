#include <iostream>
#include <string>
using std::string; 


int main(int argc, char **argv) {
    string str = string(argv[1]) + argv[2];
    std::cout << str << std::endl;
}
