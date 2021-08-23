#include "pch.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> v;
	auto it = find_if(	elements.begin(),
						elements.end(),
						[&border](const T& e) {
							return e > border;
						}	);

	for (it; it != elements.end(); it++) {
		v.push_back(*it);
	}
	
	return v;
}

int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	return 0;
}
