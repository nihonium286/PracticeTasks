#include <iostream>
#include <set>


int main()
{

	size_t n, m;
	int S, A, B, M;

	std::cin >> n >> m >> S >> A >> B >> M;

	std::multiset<int> X{ S };

	int X_prev{ S };

	for (size_t i{}; i < n - 1; i++) {
		X.insert((A * X_prev + B) % M);
		X_prev = (A * X_prev + B) % M;
	}

	int sum{};

	size_t i{};

	for (std::multiset<int>::iterator it{ X.begin() }; i < m; it++, i++) {
		sum += *it;
	}

	std::cout << sum;
}