#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

template <typename T> vector<T> operator*(vector<T> lhs, vector<T> rhs);
template <typename T> vector<T> sqr(vector<T> v);

template <typename First, typename Second> pair<First, Second> sqr(pair<First, Second> p);
template <typename First, typename Second> pair<First, Second> operator*(pair<First, Second> lhs, pair<First, Second> rhs);

template <typename Key, typename Value> map<Key, Value> sqr(map<Key, Value> m);


template <typename Key, typename Value> 
map<Key, Value> sqr(map<Key, Value> m) {
	
	map<Key, Value> n;

	for (auto p : m) {
		n[p.first] = p.second * p.second;
	}
	
	return n;
}

template <typename Key, typename Value>
map<Key, Value> operator*(map<Key, Value> lhs, map<Key, Value> rhs) {
	
	map<Key, Value> n;

	for (auto p : lhs) {
		n[p.first] = lhs.second * // not done * overload for map
	}

	return n;
}


template <typename First, typename Second>
pair<First, Second> sqr(pair<First, Second> p) {

	pair<First, Second> n;
	
	n.first = p.first*p.first;
	n.second = p.second*p.second;

	return n;
}


template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second> lhs, pair<First, Second> rhs) {
	return { lhs.first*rhs.first, lhs.second*rhs.second };
}


template <typename T>
vector<T> sqr(vector<T> v) {
	
	vector<T> n;
	for (auto x : v) {
		n.push_back(x*x);
	}

	return n;
}


template <typename T>
vector<T> operator*(vector<T> lhs, vector<T> rhs) {
	
	vector<T> n;
	if (lhs.size() != rhs.size()) {
		cout << "operator * is only defined for vectors of same size";
	}

	for (size_t i = 0; i < lhs.size(); i++) {
		n.push_back(lhs.at(i)*rhs.at(i));
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
