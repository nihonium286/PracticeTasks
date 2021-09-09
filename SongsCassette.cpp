#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

template<class BidirIt>
void quick(BidirIt first, BidirIt last, int m, int d) {

	auto pivot = *std::next(first, rand() % std::distance(first, last));

	BidirIt part = std::partition(first, last, [pivot](const int & x) {return x <= pivot; });

	int dist = std::distance(first, part) + d;

	if (dist == m) {
		return;
	}
	else if (dist < m) {
		quick(part, last, m, dist);
	}
	else if (dist > m) {
		if (std::equal(first + 1, part, first))
		{
			return;
		}
		quick(first, part, m, 0);
	}

}

int main()
{
	size_t n, m;
	int S, A, B, M;

	std::cin >> n >> m >> S >> A >> B >> M;

	std::vector<int> v{S};
	
	for (size_t i{ 1 }; i < n; i++) {
		v.push_back((A * v[i-1] + B) % M);
	}

	quick(v.begin(), v.end(), m, 0);

	std::vector<int> n_v(v.begin(), v.end());

	int sum{};

	for (size_t i{}; i < m; i++) {
		sum += n_v[i];
	}

	std::cout << sum;
}