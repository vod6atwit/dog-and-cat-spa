// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef OPTION_H
#define OPTION_H
#include "Person.h"
#include "cat.h"
#include "dog.h"
#include "review.h"
#include <string>
#include <iostream>
using namespace std;

class Option {
private:
	int optionChoice;
public:
	class InvalidOption {};
	Option() {
		optionChoice = 0;
	}
	Option(int c) {
		optionChoice = c;
	}
	void setoptionChoice(int);
	int getoptionChoice() { return optionChoice; }
	void displayOption();
};
#endif // !OPTION_H

