#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto f_it = find_if(numbers.begin(),
		numbers.end(),
		[](const int& n) {
		return n < 0;
		});

	auto it = f_it;

	while (it != numbers.begin()) {
		--it;
		cout << *it << ' ';
	}

}
/*
int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}*/