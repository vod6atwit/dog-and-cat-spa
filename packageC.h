// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef PACKAGEC_H
#define PACKAGEC_H
#include "animal.h"

class PackageC {
private:
	int feePackageC;
	int freeTrailC;
public:
	PackageC() {
		feePackageC = 0;
		freeTrailC = 0;
	}
	PackageC(int fp, int ft) {
		feePackageC = fp;
		freeTrailC = ft;
	}
	void setUpPackageC(Animal&, int&, int&);
	int getFeepackageC() { return feePackageC; }
	int getFreeTrailC() { return freeTrailC; }
	friend class Package;
};
#endif // !PACKAGEC_H

