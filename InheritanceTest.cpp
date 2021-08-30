#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


class Animal {
public:
	Animal(const string& name):Name(name){
	}
	
	const string Name;
};


class Dog : public Animal{
public:
	
	Dog(const string& name):Animal(name){
	}

	void Bark() {
		cout << Name << " barks: woof!" << endl;
	}
};

int main()
{
	Dog dog1("Bim");

	dog1.Bark();

	cout << dog1.Name;
}