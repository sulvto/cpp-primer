#include <iostream>
using std::initializer_list;

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending :word ;
}

int main(int argc, char **argv) {
    std::cout << make_plural() << std::endl;
            
    
}
