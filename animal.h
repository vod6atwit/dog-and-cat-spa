// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H
#include "information.h"
#include "edit.h"
#include "cat.h"
#include "dog.h"
#include "packageA.h"
#include "packageB.h"
#include "packageC.h"

class Animal : public Information {
protected:
	static int numAnimal;
private:
	double size;
	string name;
	string pet;
public:
	class InvalidSize {};
	class InvalidPet {};
	Animal() {
		name = "";
		size = 0;
		pet = ' ';
	}
	Animal(string n, double s, string p);
	~Animal();
	void setSize(double);
	void setPet(string);
	void setName(string n) {
		name = n;
	}
	string getPet() { return pet; }
	double getSize() { return size; }
	string getName() { return name; }
	string getAddress() { return address; }
	static int getnumAnimal() { return numAnimal; }

	void createInfor() {
		cout << " Create a animal information. ";
	}
	virtual void displayPetInfor() {
		cout << "\n Create a pet information. ";
	}

	friend class Cat;
	friend class Dog;
	friend class Edit;
	friend class PackageA;
	friend class PackageB;
	friend class PackageC;
};

class Cat : public Animal {
private:
	string breed;
public:
	Cat() {
		breed = "";
	}
	Cat(string n, double s, string b, string p) : Animal(n, s, p) {
		breed = b;
	}
	~Cat();
	string getbreed() { return breed; }
	void displaycatInfor();
	void displayPetInfor() {
		cout << "\n Create a cat information \n";
	};
};

class Dog : public Animal {
protected:
	string breed;
public:
	Dog() {
		breed = "";
	}
	Dog(string n, double s, string b, string p) : Animal(n, s, p) {
		breed = b;
	}
	~Dog();
	string getbreed() { return breed; }
	void displaydogInfor();
	void displayPetInfor() {
		cout << "\n Create a dog information \n";
	};
};
#endif // !ANIMAL_H

