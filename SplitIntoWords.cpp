#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {

	vector<string> v;

	string::const_iterator it = s.begin();

	while (it != s.end()) {

		auto f_it = it;
		it = find(it, s.end(), ' ');
		v.push_back(string(f_it,it));
		
		if (it != s.end())
			it++;
	}
	
	return v;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}