#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::ifstream;
using std::runtime_error;
using std::istringstream;

unordered_map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> trans_map;
	string key, value;

	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		} else {
			throw runtime_error("no rule for "+ key);
		}
	}
	return trans_map;
}

const string &transform(const string &word, const unordered_map<string, string> &trans_map) {
		auto map_it = trans_map.find(word);
	if (map_it != trans_map.end()) {
		return map_it->second;
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
