// Programmer Duy Vo
// Date: 12/18/19

#include "payBill.h"

istream & operator>>(istream & in, PayBill &p)
{
	cout << "Enter the amount you want to pay: ";
	in >> p.userAmount;

	while (!cin)
	{
		cin.clear();
		while (cin.get() != '\n') continue;

		cout << " we have problem with your payment. Please enter the amounts: ";
		in >> p.userAmount;
	}

	return in;
}

void PayBill::setUserPayChoice(int c)
{
	while (!cin)
	{
		cin.clear();
		while (cin.get() != '\n') continue;

		cout << " we have problem with your choice. Please enter again: ";
		cin >> c;
	}
	if (c == 1) {
		userPayChoice = c;
	}
	else
		if (c == 2) {
			userPayChoice = c;
		}
		else
			if (c == 3) {
				userPayChoice = c;
			}
			else
				throw InvalidChoice();

}

void PayBill::setUserAmount(double A)
{
	userAmount = A;
}

void PayBill::disPlayPayBill()
{
	cout
		<< "\n What is the way you want to pay for the bill: \n"
		<< " 1. pay by cash \n"
		<< " 2. pay by debit \n"
		<< " 3. pay by credit \n\n";
}
