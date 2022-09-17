// Programmer Duy Vo
// Date: 12/18/19

#include "option.h"
#include <iostream>

void Option::setoptionChoice(int c)
{
	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n') continue;

		throw InvalidOption();
	}

	if (c == 1) {
		optionChoice = c;
	}
	else
		if (c == 2) {
			optionChoice = c;
		}
		else
			if (c == 3) {
				optionChoice = c;
			}
			else
				throw InvalidOption();
}

void Option::displayOption()
{
	cout
		<< "\n Here is the options you can choose: \n"
		<< " 1. Review the information of the customer and their pet. \n"
		<< " 2. Edit the information of the customer and their pet. \n"
		<< " 3. Exit this screen and go to next page. \n\n\n";
}




