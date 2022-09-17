#pragma once
#ifndef PACKAGE_H
#define PACKAGE_H
#include "packageA.h"
// Programmer Duy Vo
// Date: 12/18/19

#include "packageB.h"
#include "packageC.h"
#include "bill.h"
#include <iostream>
using namespace std;

class Package {
private:
	int feePackage;
	int freeTrial;
	string packageChoice;
public:
	class InvalidPackageChoice {};
	Package() {
		feePackage = 0;
		freeTrial = 0;
	}
	Package(int fp, int ft, string pc) {
		feePackage = fp;
		freeTrial = ft;
		packageChoice = pc;
	}
	void setPackagechoice(string);
	int getfeePackage() { return feePackage; }
	int getfreetrail() { return freeTrial; }
	void displayPackage();

	friend ostream & operator<<(ostream &out, const Package &p);
};
#endif 	// !PACKAGE_H



