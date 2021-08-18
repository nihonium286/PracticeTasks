#include <iostream>
#include <map>
#include <string>
#include <stdexcept>


using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(const map<Key, Value>& m, const Key& k) {
	auto search = m.find(k);
	if (search != m.end()) {
		return const_cast<Value&>(search->second);		
	}
	else {
		throw runtime_error("Key is not found in dictionary");
	}
}


int main()
{
	map<int, int> m = { {0, 0} };
	int& item_i = GetRefStrict(m, 0);
	cout << item_i << endl;

	map<int, string> s = { {0, "value"} };
	string& item_s = GetRefStrict(s, 0);
	cout << item_s << endl;

	//runtime error
	/*map<int, int> m = { {0, 0} };
	int& item_i = GetRefStrict(m, 1);
	cout << item_i << endl;*/ 
}