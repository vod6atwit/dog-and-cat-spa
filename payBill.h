// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef PAYBILL_H
#define PAYBILL_H
#include "package.h"

class PayBill : public Package {
private:
	double userAmount;
	int userPayChoice;
public:
	class InvalidChoice {};
	PayBill() {
		userAmount = 0;
	}
	PayBill(double user, int fp, int ft, string pc) : Package(fp, ft, pc) {
		userAmount = user;
	}
	void setUserPayChoice(int);
	int getUserPayChoice() { return userPayChoice; }
	void setUserAmount(double A);
	double getUserAmount() { return userAmount; }
	void disPlayPayBill();
	friend istream &operator>>(istream &in, PayBill &p);
};

#endif // !PAYBILL_H

