// Programmer Duy Vo
// Date: 12/18/19

#pragma once
#ifndef INFORMATION_H
#define INFORMATION_H
#include <string>
#include <iostream>
using namespace std;

class Information {
protected:
	string address;
public:
	Information() {
		address = "";
	}
	Information(string a) {
		address = a;
	}
	virtual string getAddress() = 0;
	virtual void createInfor() {
		cout << " Creating a new person Information \n";
	}
};
#endif // !INFORMATION_H
