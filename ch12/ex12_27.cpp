#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace::std;

class TextQuery {



	TextQuery(ifstream &infile) {
		string line;
		while (getline(infile, line)) {
			content.push_back(line);
		}
		
	}

	QueryResult& query(string s);

	private:
		vector<string> content;
		map<string, set<int>> wordMap;
}

class QueryResult {
	private:
		map<int, string> m;
}

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin << s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main() {
	
}
