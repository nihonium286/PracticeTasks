#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<unsigned int> a;
	int x;
	std::cin >> x;

	while (x != -1) {
		a.push_back(x);
		std::cin >> x;
	}

	std::vector<unsigned int> b;

	std::cin >> x;

	while (x != -1) {
		b.push_back(x);
		std::cin >> x;
	}

	std::vector<unsigned int> n;

	for (auto y : b) {
		for (size_t i = 0; i < a.size(); i++) {
			if (i%y) n.push_back(a[i]);
		}
		a = n;
		n.clear();
	}

	for (auto x : a) {
		std::cout << x << ' ';
	}

	std::cout << -1;
}
