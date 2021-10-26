#include "vector.cpp"
#include <iostream>

int main() {

	ctl::Vector<int> v(2);
	v.push_back(2);

	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;

	for (int i : v) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	for (int i{}; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}


	while(1){}
	return 0;
}