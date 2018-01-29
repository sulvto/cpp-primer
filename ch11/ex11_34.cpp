#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::runtime_error;
using std::istringstream;

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key, value;

	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map.insert({key, value.substr(1)});
			// trans_map[word] = value.substr(1);
		} else {
			throw runtime_error("no rule for "+ key);
		}
	}
	return trans_map;
}

const string &transform(const string &word,const map<string, string> &trans_map) {
		auto map_it = trans_map.find(word);
	if (map_it != trans_map.end()) {
		return map_it->second;
		// return trans_map[word];
	} else {
		return word;
	}
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		string word;
		istringstream stream(text);
		bool firstword = true;
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			} else {
				cout << " ";
			}

			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main() {
	ifstream map_file("ex11_33.map.txt");
	ifstream input("ex11_33.words.txt");
	word_transform(map_file, input);
}
