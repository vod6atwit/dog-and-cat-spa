// Programmer Duy Vo
// Date: 12/18/19

//#include "dog.h"
#include "animal.h"
#include <iostream>
using namespace std;
class Animal;

Dog::~Dog()
{
	cout << " Bye bye Dog ";
}

void Dog::displaydogInfor()
{
	cout << " Animal Name: " << name << endl;
	cout << " Animal size: " << size << endl;
	cout << " The breed: " << breed << endl;
}
