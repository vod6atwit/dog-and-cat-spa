// Programmer Duy Vo
// Date: 12/18/19

#include "edit.h"
#include "Person.h"
#include "review.h"
#include <iostream>
#include <fstream>
using namespace std;

void Edit::menuEdit()
{
	cout << "1. Edit person information. " << endl;
	cout << "2. Edit animal information. " << endl;
	cout << " here is the option you can choose to edit. " << endl;
}

void Edit::personMenuEdit()
{
	cout << "1. Edit First name. " << endl;
	cout << "2. Edit Last name. " << endl;
	cout << "3. Edit Address. " << endl;
	cout << "4. Edit phone number. " << endl;
	cout << "5. Edit email: " << endl;
	cout << " Here the option you can choose to edit person information. " << endl;
}

void Edit::animalMenuEdit()
{
	cout << "1. Edit name. " << endl;
	cout << "2. Edit size. " << endl;
	cout << "3. Edit pet. " << endl;
	cout << "4. Edit breed. " << endl;
	cout << " Here the option you can choice to edit animal information. " << endl;

}

void Edit::setEditPersonChoice(Person &p, int num, string file, string name, double size, string breed, string pet)
{
	string line;
	ofstream writeTofile;
	bool tryTry = true;

	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n') continue;

		throw Invalidchoice();
	}

	if (num == 1) {
		cout << " Your old first Name is: " << p.getFirstName() << endl;
		cout << " Enter your new first name: ";
		cin >> ws;
		getline(cin, line);
		p.setFirstName(line);
	}
	else {

		if (num == 2) {
			cout << " Your old last Name is: " << p.getLastName() << endl;
			cout << " Enter your new Last name: ";
			cin >> ws;
			getline(cin, line);
			p.setLastName(line);
		}
		else {
			if (num == 3) {
				cout << " Your old address is: " << p.getAddress() << endl;
				cout << " Enter your new address: ";
				cin >> ws;
				getline(cin, line);
				p.setAddress(line);
			}
			else {
				if (num == 4) {
					cout << " Your old phone number is: " << p.getPhoneNumber() << endl;
					cout << " Enter your new phone number: ";
					cin >> ws;
					getline(cin, line);

					while (tryTry) {
						try
						{
							p.setphoneNumber(line);
							tryTry = false;
						}
						catch (Person::InvalidphoneNumber) {
							cout << " Valid phone number must have 10 digits. Please enter again: ";
							cin >> ws;
							getline(cin, line);
						}
					}
				}
				else {
					tryTry = true;
					if (num == 5) {
						cout << " Your old email is: " << p.getEmail() << endl;
						cout << " Enter your new email: ";
						cin >> ws;
						getline(cin, line);

						while (tryTry) {
							try
							{
								p.setEmail(line);
								tryTry = false;
							}
							catch (Person::InvalidEmail) {
								cout << " Valid email must have \'@\' and \'.\' in it. Please enter again: ";
								cin >> ws;
								getline(cin, line);
							}
						}
					}
					else
						throw Invalidchoice();
				}
			}
		}
	}

	writeTofile.open(file);

	writeTofile << " First name: " << p.getFirstName() << endl;
	writeTofile << " Last name: " << p.getLastName() << endl;
	writeTofile << " address: " << p.getAddress() << endl;
	writeTofile << " Phone number: " << p.getPhoneNumber() << endl;
	writeTofile << " Email: " << p.getEmail() << endl;

	writeTofile << " Animal Name: " << name << endl;
	writeTofile << " Animal size: " << size << endl;
	writeTofile << " dog breed: " << breed << endl;

	if (pet == "d" || pet == "D") {
		writeTofile << " Animal type: dog " << endl;
	}
	else
		if (pet == "c" || pet == "C") {
			writeTofile << " Animal type: cat " << endl;
		}
	writeTofile.close();
}

void Edit::setEditAnimalChoice(Person &p, Animal &a, int num, string file, string &breed, string pet)
{
	string newBreed;
	string line;
	double s;
	ofstream writeTofile;
	bool tryTry = true;

	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n') continue;

		throw Invalidchoice();
	}

	if (num == 1) {
		cout << " Your old animal name is: " << a.getName() << endl;
		cout << " Enter your new animal name: ";
		cin >> ws;
		getline(cin, line);
		a.setName(line);
	}
	else
		if (num == 2) {
			cout << " Your old animal size is: " << a.getSize() << endl;
			cout << " Enter your new animal size: ";
			cin >> s;
			bool tryAgain = true;
			while (tryAgain) {
				try
				{
					a.setSize(s);
					tryAgain = false;
				}
				catch (Animal::InvalidSize) {
					cout << "The size should be positive number. Try again: ";
					cin >> s;
				}
			}
		}
		else
			if (num == 3) {
				cout << " Your old animal pet is: " << a.getPet() << endl;
				cout << " Enter again your pet (d) for dog and (c) for cat: ";
				cin >> pet;
				//cin.ignore(100, '\n');
				bool tryAgain = true;
				while (tryAgain) {
					try
					{
						a.setPet(pet);
						tryAgain = false;
					}
					catch (Animal::InvalidPet) {
						cout << "We only have the service for dog or cat, enter (d) for dog and (c) for cat. Try again: ";
						cin >> pet;
					}
				}

			}
			else
				if (num == 4) {
					cout << " Your old animal breed is: " << breed << endl;
					cout << " Enter again your animal breed: ";
					cin >> newBreed;
					breed = newBreed;
				}
				else
					throw Invalidchoice();

	writeTofile.open(file);

	writeTofile << " First name: " << p.getFirstName() << endl;
	writeTofile << " Last name: " << p.getLastName() << endl;
	writeTofile << " address: " << p.getAddress() << endl;
	writeTofile << " Phone number: " << p.getPhoneNumber() << endl;
	writeTofile << " Email: " << p.getEmail() << endl;

	writeTofile << " Animal Name: " << a.getName() << endl;
	writeTofile << " Animal size: " << a.getSize() << endl;
	writeTofile << " animal breed: " << breed << endl;

	if (pet == "d" || pet == "D") {
		writeTofile << " Animal type: dog " << endl;
	}
	else
		if (pet == "c" || pet == "C") {
			writeTofile << " Animal type: cat " << endl;
		}

	writeTofile.close();
}


