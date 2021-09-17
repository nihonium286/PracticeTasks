/*
	There is a sequence of numbers. Print it in reverse order.
*/

#include <iostream>
#include <vector>

using uint = unsigned int;

int main()
{
	std::vector<uint> a;
	uint i;
	std::cin >> i;
		
	while (i != -1) {
		a.push_back(i);
		std::cin >> i;
	}

	for (std::vector<uint>::reverse_iterator it = a.rbegin(); it != a.rend(); it++) { std::cout << *it << ' '; }

	std::cout << -1;
}
