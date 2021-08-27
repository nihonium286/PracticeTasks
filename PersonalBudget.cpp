#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void RequestHandler() {
	string request;
	getline(cin, request);

	string::iterator it = find(request.begin(), request.end(), ' ');
	string::iterator it2 = find(next(it), request.end(), ' ');
	string::iterator it3 = find(next(it2), request.end(), ' ');

	if (string(request.begin(),it) == "Earn") {
		string from(it, it2);
		string to(it2, it3);
		unsigned int value = stoi(string(it3, request.end()));
	}
}

int main()
{

	size_t q;
	cin >> q;

	while (q--) {
		
	}

    cout << "Hello World!\n"; 
}