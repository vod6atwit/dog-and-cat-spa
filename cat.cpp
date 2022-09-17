// Programmer Duy Vo
// Date: 12/18/19

#include "animal.h"
#include "information.h"
#include <iostream>
using namespace std;
class Animal;

Cat::~Cat()
{
	cout << " Done saving cat information ";
}

void Cat::displaycatInfor()
{
	cout << " Animal Name: " << name << endl;
	cout << " Animal size: " << size << endl;
	cout << " The breed: " << breed << endl;
}
