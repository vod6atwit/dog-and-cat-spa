// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef PACKAGEB_H
#define PACKAGEB_H
#include "animal.h"
class Animal;

class PackageB {
private:
	int feePackageB;
	int freeTrailB;
public:
	PackageB() {
		feePackageB = 0;
		freeTrailB = 0;
	}
	PackageB(int fp, int ft) {
		feePackageB = fp;
		freeTrailB = ft;
	}
	void setUpPackageB(Animal&, int&, int&);
	int getfeePackageB() { return feePackageB; }
	int getfreeTrailB() { return freeTrailB; }
	friend class Package;
};
#endif // !PACKAGEB_H

