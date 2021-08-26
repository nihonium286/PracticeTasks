/*
�������� ��������� ������� RemoveDuplicates, ����������� �� ������ ������ elements �������� ���� T 
� ��������� �� ���� ��� ��������� ���������. ������� ���������� ��������� ����� ���� �����.

�������������, ��� ������� ���� T ����� ���������� � ������� ���������� ==, !=, < � >.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
	set<T> n(elements.begin(), elements.end());
	elements.erase(elements.begin(), elements.end());
	elements.insert(elements.begin(), n.begin(), n.end());
}

int main() {
	vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	RemoveDuplicates(v1);
	for (int x : v1) {
		cout << x << " ";
	}
	cout << endl;
	
    // operator << overload for string is neccessary for this part to work
	/* 
	vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	for (const string& s : v2) {
		cout << s << " ";
	}
	cout << endl; */
	return 0;
}