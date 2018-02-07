#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>

using namespace::std;

class QueryResult;
using line_no = vector<string>::size_type;

class TextQuery {

	public:
		TextQuery(ifstream&);
		QueryResult query(const string&) const;

	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wordMap;
};

TextQuery::TextQuery(ifstream &infile):file(new vector<string>) {
	string text;
    while (getline(infile, text)) {
    	file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wordMap[word];
			if (!lines) {
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
    }
};

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
	public:
		QueryResult(string s, 
						shared_ptr<set<line_no>> p, 
						shared_ptr<vector<string>> f):
			sought(s), lines(p), file(f) {}

	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};


QueryResult TextQuery::query(const string &s) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wordMap.find(s);
	if (loc == wordMap.end()) {
		return QueryResult(s, nodata, file);
	} else {
		return QueryResult(s, loc->second, file);
	}
}


ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;
	}
	return os;
}

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}


int main() {
	ifstream input("ex12_30.cpp");
   	runQueries(input);
}
