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

	char* arr;
	arr = v3.data();

	for (size_t i{}; i < sizeof(arr); i++) {
		std::cout << arr[i] << ' ';
	}

	std::cout << sizeof(arr) << std::endl; // why arr contains 4 elements?

	for (size_t i{}; i < v.size(); i++) {  // exception is thrown if i is out of range of v
		std::cout << v.at(i) << ' ';
	}

	std::cout << std::endl;

	ctl::Vector<int> v4;

	std::cout << v3.empty() << ' ' << v4.empty() << std::endl;

	//v4.pop_back();  Calling pop_back on an empty container results in undefined behavior.

	v4.push_back(4);

	std::cout << v4[0];

	std::cout << std::endl;

	while(1){}
	return 0;
}