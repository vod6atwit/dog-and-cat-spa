// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef PACKAGEA_H
#define PACKAGEA_H
#include "animal.h"
class Animal;

class PackageA {
private:
	int feePackageA;
	int freeTrailA;
public:
	PackageA() {
		feePackageA = 0;
		freeTrailA = 0;
	}
	PackageA(int fp, int ft) {
		cout << "\n Created package A. ";
		feePackageA = fp;
		freeTrailA = ft;
	}
	void setUpPackageA(Animal&, int &fp, int &ft);
	int getfeePackageA() { return feePackageA; }
	int getfreetrailA() { return freeTrailA; }
	friend class Package;

};
#endif // !PACKAGEA_H

