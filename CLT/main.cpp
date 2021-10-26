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

	for (size_t i{}; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}

	std::cout << std::endl;

	ctl::Vector<int> v2 = v;

	for (int i : v2) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	ctl::Vector<char> v3(10);

	v3.assign(3, 'a');

	for (int i : v3) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	for (auto i : v3) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	while(1){}
	return 0;
}