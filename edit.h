// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef EDIT_H
#define EDIT_H
#include "review.h"

class Person;
class Animal;
class Cat;
class Dog;

class Edit {
private:
	int editChoice;
public:
	class Invalidchoice {};
	Edit() {
		editChoice = 0;
	}
	Edit(int e) {
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n') continue;

			throw Invalidchoice();
		}
		if (e == 1) {
			editChoice = e;
		}
		else
			if (e == 2) {
				editChoice = e;
			}
			else
				throw Invalidchoice();
	}

	int getEditChoice() { return editChoice; }
	void menuEdit();
	void personMenuEdit();
	void animalMenuEdit();
	void setEditPersonChoice(Person&, int num, string, string, double, string, string);
	void setEditAnimalChoice(Person&, Animal&, int num, string, string&, string);
};
#endif // !EDIT_H

