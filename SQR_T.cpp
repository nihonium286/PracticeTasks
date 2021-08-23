/*
Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, но и для контейнеров. 
Функция должна возвращать копию исходного контейнера, модифицировав его следующим образом:
 - для vector элементы нужно возвести в квадрат;
 - для map в квадрат нужно возвести только значения, но не ключи;
 - для pair в квадрат нужно возвести каждый элемент пары.
 
 Функция должна корректно работать не только для контейнеров, состоящих из чисел, 
 но и для составных объектов, например, векторов словарей пар чисел.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

template <typename T> vector<T> sqr(vector<T> v);

template <typename First, typename Second> pair<First, Second> sqr(pair<First, Second> p);

template <typename Key, typename Value> map<Key, Value> sqr(map<Key, Value> m);


template <typename T> 
T sqr(T x) { 
	return x * x; 
};

template <typename Key, typename Value> 
map<Key, Value> sqr(map<Key, Value> m) {
	
	map<Key, Value> n;

	for (auto p : m) {
		n[p.first] = sqr(p.second);
	}
	
	return n;
}

template <typename First, typename Second>
pair<First, Second> sqr(pair<First, Second> p) {

	pair<First, Second> n;

	n.first = sqr(p.first);
	n.second = sqr(p.second);

	return n;
}


template <typename T>
vector<T> sqr(vector<T> v) {
	
	vector<T> n;
	for (auto x : v) {
		n.push_back(sqr(x));
	}

	return n;
}

int main()
{
	vector<vector<double>> v = { {1,2,3}, {1,2,3} };
	
	for (auto x : sqr(v)) {
		for (auto y : x) {
			cout << ' ' << y;
		}
	}
	cout << endl;

	pair<int, int> p = { 1,2 };

	pair<int, int> n = sqr(p);

	cout << n.first << ' ' << n.second;

	cout << endl;

	vector<pair<double, int>> vp = { {1,2}, {1,2} };

	for (auto x : sqr(vp)) {
		cout << x.first << ' ' << x.second << ' ';
	}

	cout << endl;


	map<int, double> m = { {1,1},{2,2},{3,3} };

	for (auto x : sqr(m)) {
		cout << x.first << ' ' << x.second << ' ';
	}

	cout << endl;
	
}
