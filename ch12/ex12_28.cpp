#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace::std;

vector<string> toVector(ifstream &infile) {
	string line;
	vector<string> content;
	while (getline(infile, line)) {
		content.push_back(line);
	}
	return content;
}

void runQueries(ifstream &infile) {
	vector<string> content(toVector(infile));

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		map<size_t, string> lineMap;
		for (size_t i=0; i<content.size(); i++) {
			string line = content[i];
			istringstream stream(line);
			string word;
			while (stream >> word) {
				if (word == s) {
					lineMap.insert({i + 1, line});
				}
			}
		}
		cout << s << " occurs " << lineMap.size() << " times" << endl;
		for (const auto &p : lineMap) {
			cout << "(line " << p.first << ") " << p.second << '\n';
		}
		cout << endl;
	}
}

int main() {
	ifstream input("ex12_28.cpp");
	runQueries(input);
}
