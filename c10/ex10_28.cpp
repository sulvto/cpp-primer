#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>

using std::vector;
using std::deque;
using std::string;
using std::cout;
using std::endl;


int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vec1;
	vector<int> vec2;
	deque<int> vec3;

	copy(vec.begin(), vec.end(), inserter(vec1, vec1.begin()));
	copy(vec.begin(), vec.end(), back_inserter(vec2));
	copy(vec.begin(), vec.end(), front_inserter(vec3));

	for_each(vec1.begin(), vec1.end(), [](int i){ cout << i << " ";});
	cout << endl;
	for_each(vec2.begin(), vec2.end(), [](int i){ cout << i << " ";});
	cout << endl;
	for_each(vec3.begin(), vec3.end(), [](int i){ cout << i << " ";});
	cout << endl;
}
