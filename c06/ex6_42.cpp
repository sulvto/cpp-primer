#include <iostream>
#include <string>
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending :word ;
}

int main(int argc, char **argv) {
    string success = "success";
    string failure = "failure";
    std::cout << make_plural(success.size(), success, "") << std::endl;
    std::cout << make_plural(failure.size(), failure) << std::endl;       
}
