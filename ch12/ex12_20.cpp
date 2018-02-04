#include <iostream>
#include <stdexcept>
#include "ex12_19.cpp"

using namespace std;

int main() {
    string word;
    StrBlob sb;
    while (cin >> word) {
        sb.push_back(word);
    }

    StrBlobPtr begin =  sb.begin();

    cout << "output: ";
    while (true) {
		try {
        	cout << begin.deref() << " ";
        	begin.incr();
		} catch (out_of_range) {
			break;
		}
    }

    cout << endl;
    return 0;
}
