// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef PERSON_H
#define PERSON_H
#include "Information.h"
#include "edit.h"
#include "animal.h"
#include <iostream>
#include <string>
#include "cat.h"
#include "dog.h"
//using namespace std;

class Person : public Information {
protected:
	static int numofPerson;
private:
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
public:
	class InvalidphoneNumber {};
	class InvalidEmail {};
	Person() {
		firstName = "";
		lastName = "";
		email = "";
		phoneNumber = "";
	}
	Person(string f, string l, string a, string p, string e);
	~Person();
	void setphoneNumber(string);
	void setEmail(string);
	void setFirstName(string f) {
		firstName = f;
	}
	void setLastName(string l) {
		lastName = l;
	}
	void setAddress(string a) {
		address = a;
	}
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getAddress() { return address; }
	string getEmail() { return email; }
	static int getnumPerson() { return numofPerson; }
	string getPhoneNumber() { return phoneNumber; }

	void createInfor() {
		cout << " Created a person information. ";
	}
	void displayPerson();

	friend class Edit;
};
#endif // !PERSON_H

