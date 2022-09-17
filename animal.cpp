// Programmer Duy Vo
// Date: 12/18/19


#include "animal.h"
//#include "cat.h"
//#include "dog.h"
//#include <iostream>
//using namespace std;

int Animal::numAnimal = 0;
Animal::Animal(string n, double s, string p)
{
	name = n;
	size = s;
	pet = p;

	numAnimal++;
}

Animal::~Animal()
{
	//cout << " Bye bye animal ";
	numAnimal--;
}

void Animal::setSize(double s)
{
	while (cin.fail()) // return false when user not enter the number make the error state of the buffer 
	{
		cin.clear(); //  used to clear the error state of the buffer
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');                
		cin.ignore(100, '\n'); //used to ignore the rest of the line after the first instance of error that has occurred and it skips to or moves to the next line 
		throw InvalidSize();
	}
	while (s < 0)
	{
		if (s != static_cast<int>(s))  // occur when user enter a negative decimal number
		{
			throw InvalidSize();
		}
		else                                   // occur when user enter a negative number
		{
			throw InvalidSize();
		}
	}
	size = s;
}

void Animal::setPet(string p)
{
	if (p == "D" || p == "d") {
		pet = p;
	}
	else
		if (p == "c" || p == "C") {
			pet = p;
		}
		else
			throw InvalidPet();
}

