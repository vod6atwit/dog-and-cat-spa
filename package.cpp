// Programmer Duy Vo
// Date: 12/18/19

#include "package.h"

void Package::setPackagechoice(string choice)
{
	if (choice == "A" || choice == "a") {
		packageChoice = choice;
	}
	else
		if (choice == "B" || choice == "b") {
			packageChoice = choice;
		}
		else
			if (choice == "c" || choice == "C") {
				packageChoice = choice;
			}
			else
				throw InvalidPackageChoice();
}

void Package::displayPackage()
{
	cout << "\n Welcome to our dog and cat spa. Here is the Packages we can do for you: " << endl;
	cout << " Package A: Grooming. " << endl;
	cout << " Package B: Injection care. " << endl;
	cout << " Package C: Grooming and Injection care. " << endl;
	cout << " Enter the package you want we do for your pet: ";
}

ostream & operator<<(ostream & out, const Package &p)
{

	out << "\n\n You chose package: " << p.packageChoice << endl;
	out << " You have " << p.freeTrial << " free trail. " << endl;
	out << " The fee you have to pay now is: $" << p.feePackage << endl;
	out << " Plus tax is : $" << (double)p.feePackage * 0.06 << endl;
	out << " The total is: $" << p.feePackage + (((double)p.feePackage)*(0.06)) << endl;

	return out;
}

