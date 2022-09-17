// Programmer Duy Vo
// Date: 12/18/19

#include "Person.h"
#include "information.h"
#include <iostream>
using namespace std;

int Person::numofPerson = 0;
Person::Person(string f, string l, string a, string p, string e) :Information(a)
{
	firstName = f;
	lastName = l;
	email = e;
	phoneNumber = p;

	numofPerson++;

}

Person::~Person()
{
	numofPerson--;
}

void Person::setphoneNumber(string p)
{
	if (p.length() == 10) {
		cout << " phone number accepted" << endl;
		phoneNumber = p;
	}
	else
		throw InvalidphoneNumber();
}

void Person::setEmail(string em)
{
	auto b = em.begin(), e = em.end();
	if ((b = find(b, e, '@')) != e && find(b, e, '.') != e)
	{
		cout << "Email accepted" << endl;
		email = em;

	}
	else
	{
		cout << "Email rejected" << endl;
		throw InvalidEmail();
	}
}

void Person::displayPerson()
{
	cout << " Information of person: " << endl;
	cout << " First name: " << firstName << endl;
	cout << " Last name: " << lastName << endl;
	cout << " Address: " << address << endl;
	cout << " Email: " << email << endl;
	cout << " Phone number: " << phoneNumber << endl;
}
