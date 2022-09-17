// Programmer Duy Vo
// Date: 12/18/19

#include "packageA.h"

void PackageA::setUpPackageA(Animal &a, int &fp, int &ft)
{

	if (a.getPet() == "d" || a.getPet() == "D") {
		if (a.getSize() > 50) {
			cout << "\n Your pet size is " << a.getSize() << " lb that's a large dog ( over 50 pound ), the price for grooming is $40. " << endl;
			cout << " You have 2 free time if you use this service more than 4 times per 6 months. " << endl;
			fp = 40;
			ft = 2;
		}
		else
		{
			cout << "\n Your pet size is " << a.getSize() << " lb that's a medium dog, the price for grooming is $25. " << endl;
			cout << " You have 1 free time if you use this service more than 4 times per 6 months. " << endl;
			fp = 25;
			ft = 1;
		}
	}
	else
		if (a.getPet() == "c" || a.getPet() == "c") {
			if (a.getSize() > 10) {
				cout << "\n Your pet size is " << a.getSize() << " lb that's a large cat ( over 8 pound ), the price for grooming is $30. " << endl;
				cout << " You have 2 free time if you use this service more than 4 times per 6 months. " << endl;
				fp = 30;
				ft = 2;
			}
			else
			{
				cout << "\n Your pet size is " << a.getSize() << " lb that's a medium cat, the price for grooming is $20. " << endl;
				cout << " You have 1 free time if you use this service more than 4 times per 6 months. " << endl;
				fp = 20;
				ft = 1;
			}
		}
}
