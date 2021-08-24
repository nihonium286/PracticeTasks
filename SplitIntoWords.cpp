/*
Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.

Гарантируется, что:
- строка непуста;
- строка состоит лишь из латинских букв и пробелов;
- первый и последний символы строки не являются пробелами;
- строка не содержит двух пробелов подряд.

Подсказка
Рекомендуется следующий способ решения задачи:

- искать очередной пробел с помощью алгоритма find;
- создавать очередное слово с помощью конструктора строки по двум итераторам.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {

	vector<string> v;

	string::const_iterator it = s.begin();

	while (it != s.end()) {

		auto f_it = it;
		it = find(it, s.end(), ' ');
		v.push_back(string(f_it,it));
		
		if (it != s.end())
			it++;
	}
	
	return v;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}
