// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef REVIEW_H
#define REVIEW_H
#include "option.h"
#include "Person.h"
#include "dog.h"
#include "cat.h"
#include <iostream>
using namespace std;

class Review {
private:
	string fileName;
public:
	Review() {
		fileName = "";
	}
	Review(string fName) {
		fileName = fName;
	}
	string getFileName() { return fileName; }
	void printout();
};
#endif // !REVIEW_H

