// Programmer Duy Vo
// Date: 12/18/19

#include "packageC.h"

void PackageC::setUpPackageC(Animal &a, int &fp, int &ft)
{
	if (a.getPet() == "d" || a.getPet() == "D") {
		if (a.getSize() > 50) {
			cout << "\n Your pet size is " << a.getSize() << " lb that's a large dog ( over 50 pound ), the price for boths (grooming and injection care) is $80. " << endl;
			cout << " You have 2 free time if you use this whole service more than 5 times per years. " << endl;
			fp = 80;
			ft = 2;
		}
		else
		{
			cout << "\n Your pet size is " << a.getSize() << " lb that's a medium dog, the price for boths (grooming and injection care) is $50. " << endl;
			cout << " You have 1 free time if you use this whole service more than 5 times per year. " << endl;
			fp = 50;
			ft = 1;
		}
	}
	else
		if (a.getPet() == "c" || a.getPet() == "c") {
			if (a.getSize() > 10) {
				cout << "\n Your pet size is " << a.getSize() << " lb that's a large cat ( over 8 pound ), the price for boths (grooming and injection care) is $60. " << endl;
				cout << " You have 2 free time if you use this whole service more than 5 times per year. " << endl;
				fp = 60;
				ft = 2;
			}
			else
			{
				cout << "\n Your pet size is " << a.getSize() << " lb that's a medium cat, the price for injection care is $35. " << endl;
				cout << " You have 1 free time if you use this whole service more than 5 times per year. " << endl;
				fp = 35;
				ft = 1;
			}
		}
}
