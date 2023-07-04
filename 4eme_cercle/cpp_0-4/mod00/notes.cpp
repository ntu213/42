// Fichier MyClass.hpp
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
private:
	int myInt;
	double myDouble;
	std::string myString;

public:
	// Constructeur par défaut
	MyClass();

	// Constructeur avec paramètres
	MyClass(int i, double d, const std::string& str);

	// Méthode publique
	void printValues() const;
};

#endif

// Fichier MyClass.cpp
#include "MyClass.hpp"
#include <iostream>

// Implémentation des membres de la classe

MyClass::MyClass() : myInt(0), myDouble(0.0), myString("") {
}

MyClass::MyClass(int i, double d, const std::string& str) : myInt(i), myDouble(d), myString(str) {
}

void MyClass::printValues() const {
	std::cout << "myInt: " << myInt << std::endl;
	std::cout << "myDouble: " << myDouble << std::endl;
	std::cout << "myString: " << myString << std::endl;
}

// Fichier main.cpp
#include "MyClass.hpp"

int main() {
	MyClass obj1; // Utilisation du constructeur par défaut
	obj1.printValues();

	MyClass obj2(42, 3.14, "Hello"); // Utilisation du constructeur avec paramètres
	obj2.printValues();

	return 0;
}
