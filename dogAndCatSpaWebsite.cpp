// Programmer Duy Vo
// Date: 12/18/19
// Purpose: creating a website for dog and cat spa
// get information about the customer and their pets
// let them fix it if something wrong
// get all that informations and save it into a file
// calculate the price and let them pay.


#include <iostream>
#include <string>
#include <fstream>
#include "information.h"
#include "Person.h"
#include "option.h"
#include "animal.h"
//#include "cat.h"
//#include "dog.h"
#include "edit.h"
#include "review.h"
#include "package.h"
#include "packageA.h"
#include "packageB.h"
#include "packageC.h"
#include "payBill.h"
using namespace std;

template <class T>
T totalBill(T fee, T tax, T feeAndTax) { // template calculate the total fee
	return fee + (tax*feeAndTax);
}

template <class T>
T change(T totalFee, T userAmount) { // template calculate the change we have to give back to the customer
	return userAmount - totalFee;
}

template <class T>
T remain(T totalFee, T userAmount) { // template calculate how much the customer need to pay more to complete the bill
	return totalFee - userAmount;
}

int getvalidOption(Option &);

int main() {

	ofstream writeTofile; // use the data type ofstream to write the information in the file 
	ifstream readFile;   // use the data type ifstream to read the information in the file
	string pet, newPet;
	string firstName, lastName, address, email, phoneNumber, fileName;
	string newFirstName, newLastname, newAddress, newEmail, newPhoneNumber;
	string animalName, animalNewName, breed, newBreed;
	string PackageChoice;
	double size, newSize, userAmount, totalFee, reMain;
	int optionChoice;
	int editChoice, editPersonChoice, editAnimalChoice;
	int feePackage = 0, freeTrail = 0, feePackageA = 0, freeTrailA = 0, feePackageB = 0, freeTrailB = 0, feePackageC = 0, freeTrailC = 0;
	int userPayChoice;
	bool tryAgain = true;

	Person person;
	Animal animal;
	Option option;
	Edit edit;
	//Dog dog;
	//Cat cat;
	Package package;
	PackageA packageA;
	PackageB packageB;
	PackageC packageC;

	PayBill *ptrPayBill;

	cout << " Enter the file name you want to save the information: ";
	cin >> ws;
	getline(cin, fileName);

	writeTofile.open(fileName);  // open that file name to write into it

	cout << " Enter the first name of the customer: ";
	cin >> ws;
	getline(cin, firstName);      // ask user enter the first name 
	writeTofile << " First name: " << firstName << endl;  // write that file name into the file 

	cout << " Enter the last name of the customer: ";
	cin >> ws;
	getline(cin, lastName);    // ask user enter the last name 
	writeTofile << " Last name: " << lastName << endl;    // write that last name into the file 

	cout << " Enter the address of the customer: ";
	cin >> ws;
	getline(cin, address);   // ask user enter the address 
	writeTofile << " address: " << address << endl;   // write that adress into the file 

	cout << " Enter the phone number of the customer: ";
	cin >> ws;
	getline(cin, phoneNumber); // ask user enter the phone number 

	while (tryAgain) {
		try
		{
			person.setphoneNumber(phoneNumber);
			tryAgain = false;
		}
		catch (Person::InvalidphoneNumber) {
			cout << " Valid phone number must have 10 digits. Please enter again: ";
			cin >> ws;
			getline(cin, phoneNumber);
		}
	}
	writeTofile << " Phone number: " << phoneNumber << endl; // write that number phone into the file 

	cout << " Enter the email of the customer: ";
	cin >> ws;
	getline(cin, email);

	tryAgain = true;
	while (tryAgain) {
		try
		{
			person.setEmail(email);
			tryAgain = false;
		}
		catch (Person::InvalidEmail) {
			cout << " Valid email must have \'@\' and \'.\' in it. Please enter again: ";
			cin >> ws;
			getline(cin, email);
		}
	}
	writeTofile << " Email: " << email << endl;

	Person customer(firstName, lastName, address, phoneNumber, email);
	customer.createInfor();

	cout << "\n-------------------------------------------\n";

	cout << " Enter " << customer.getFirstName() << " " << customer.getLastName() << "'s animal name: ";
	cin >> ws;
	getline(cin, animalName);
	writeTofile << " Animal Name: " << animalName << endl;

	cout << " Enter the size of the animal(pound): ";
	cin >> size;
	cin.ignore(100, '\n');

	tryAgain = true;
	while (tryAgain) {
		try
		{
			animal.setSize(size);
			tryAgain = false;
		}
		catch (Animal::InvalidSize) {
			cout << "The size should be positive number. Try again: ";
			cin >> size;
		}
	}
	writeTofile << " Animal size: " << size << endl;

	cout << " Enter the pet you have, (d) for dog or (c) for cat : ";
	cin >> pet;
	//cin.ignore(100, '\n');

	tryAgain = true;
	while (tryAgain) {
		try
		{
			animal.setPet(pet);
			tryAgain = false;
		}
		catch (Animal::InvalidPet) {
			cout << "We only have the service for dog or cat, enter (d) for dog and (c) for cat. Try again: ";
			cin >> pet;
		}
	}

	if (pet == "d" || pet == "D") {
		writeTofile << " Animal type: dog " << endl;
		cout << " Enter the breed of your dog: ";
		cin >> ws;
		getline(cin, breed);
		writeTofile << " Animal breed: " << breed << endl;
		Dog dog(animalName, size, breed, pet);
		dog.createInfor();
		dog.displayPetInfor();
		//dog.displaydogInfor();
	}
	else
		if (pet == "c" || pet == "C") {
			writeTofile << " Animal type: cat " << endl; // write pet to file 
			cout << " Enter the breed of your cat: ";
			cin >> ws;
			getline(cin, breed);
			writeTofile << " Animal breed: " << breed << endl; // write breed to file
			Cat cat(animalName, size, breed, pet);
			cat.createInfor();
			cat.displayPetInfor();
			//cat.displaycatInfor();
		}

	cout << "\n---------------------------------------\n";

	option.displayOption();
	optionChoice = getvalidOption(option);

	bool keeptry = true;
	int x = 1; // flag for set edit animal choice 
	int y = 1; // flag for set edit person choice 

	while (keeptry) {

		Option optionDecision(optionChoice);

		while (optionDecision.getoptionChoice() == 1) {

			Review review(fileName);
			review.printout();

			option.displayOption();
			optionChoice = getvalidOption(option);

			Option optionDecision(optionChoice);

			if (optionDecision.getoptionChoice() == 2) {
				break;
			}
			if (optionDecision.getoptionChoice() == 3) {
				break;
			}
		}

		while (optionDecision.getoptionChoice() == 2) {

			bool try1 = true;

			edit.menuEdit();

			cout << "\n Enter your choice: ";
			cin >> editChoice;

			while (try1) {
				try
				{
					Edit fix(editChoice);

					if (fix.getEditChoice() == 1) {

						fix.personMenuEdit();

						cout << "\n Enter your choice to edit person information: ";
						cin >> editPersonChoice;

						tryAgain = true;

						while (tryAgain) {
							try
							{
								if (y == 1) {

									do {

										fix.setEditPersonChoice(customer, editPersonChoice, fileName, animalName, size, breed, pet);

										newFirstName = customer.getFirstName();
										newLastname = customer.getLastName();
										newAddress = customer.getAddress();
										newPhoneNumber = customer.getPhoneNumber();
										newEmail = customer.getEmail();

										y = 2;

									} while (y == 1);

								}
								Person newCustomer(newFirstName, newLastname, newAddress, newPhoneNumber, newEmail);

								if (y == 3) {

									fix.setEditPersonChoice(newCustomer, editPersonChoice, fileName, animalName, size, breed, pet);

									newFirstName = newCustomer.getFirstName();
									newLastname = newCustomer.getLastName();
									newAddress = newCustomer.getAddress();
									newPhoneNumber = newCustomer.getPhoneNumber();
									newEmail = newCustomer.getEmail();

								}
								y = 3;
								tryAgain = false;

							}
							catch (Edit::Invalidchoice) {
								cout << "\n Please enter your choice again ( 1-5 ). Try agian: ";
								cin >> editPersonChoice;
							}
						}

						option.displayOption();
						optionChoice = getvalidOption(option);

					}

					Person newCustomer(newFirstName, newLastname, newAddress, newPhoneNumber, newEmail);

					if (fix.getEditChoice() == 2) {
						fix.animalMenuEdit();

						cout << "\n Enter your choice to edit animal information: ";
						cin >> editAnimalChoice;

						tryAgain = true;

						while (tryAgain) {
							try
							{
								if (x == 1) {

									do {
										Animal animal(animalName, size, pet);
										fix.setEditAnimalChoice(newCustomer, animal, editAnimalChoice, fileName, breed, pet);

										newSize = animal.getSize();
										animalNewName = animal.getName();
										newBreed = breed;
										newPet = animal.getPet();

										x = 2;

									} while (x == 1);

								}
								Animal animalNew(animalNewName, newSize, newPet);

								if (x == 3) {

									fix.setEditAnimalChoice(newCustomer, animalNew, editAnimalChoice, fileName, newBreed, pet);

									newSize = animalNew.getSize();
									animalNewName = animalNew.getName();
									newBreed = newBreed;
									newPet = animalNew.getPet();

								}
								x = 3;
								tryAgain = false;

							}
							catch (Edit::Invalidchoice) {
								cout << "\n Please enter your choice again ( 1-4 ). Try agian: ";
								cin >> editAnimalChoice;
							}

						}

						option.displayOption();
						optionChoice = getvalidOption(option);

					}

					try1 = false;

				}
				catch (Edit::Invalidchoice) {
					cout << "\n Please enter your choice again ( 1 or 2 ). Try agian: ";
					cin >> editChoice;
				}
			}

			Option optionDecision(optionChoice);
			if (optionDecision.getoptionChoice() == 1) {
				break;
			}
			if (optionDecision.getoptionChoice() == 3) {
				break;
			}
		}

		if (optionDecision.getoptionChoice() == 3) {
			keeptry = false;
		}
	}

	cout << "\n----------------------------------------\n";

	package.displayPackage();
	cin >> PackageChoice;

	tryAgain = true;
	while (tryAgain) {
		try
		{
			package.setPackagechoice(PackageChoice);
			tryAgain = false;
		}
		catch (Package::InvalidPackageChoice)
		{
			cout << " Enter again your package choice. (A) for package A, (B) for package B and (C) for package C: ";
			cin >> PackageChoice;
		}
	}

	if (PackageChoice == "a" || PackageChoice == "A") {

		if (x == 1) {
			Animal animal(animalName, size, pet);

			packageA.setUpPackageA(animal, feePackageA, freeTrailA);

			Package yourPackage(feePackageA, freeTrailA, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageA, 0.06, (double)feePackageA);
		}
		if (x == 3) {
			Animal newAnimal(animalNewName, newSize, newPet);

			packageA.setUpPackageA(newAnimal, feePackageA, freeTrailA);

			Package yourPackage(feePackageA, freeTrailA, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageA, 0.06, (double)feePackageA);
		}
	}
	if (PackageChoice == "b" || PackageChoice == "B") {

		if (x == 1) {
			Animal animal(animalName, size, pet);

			packageB.setUpPackageB(animal, feePackageB, freeTrailB);

			Package yourPackage(feePackageB, freeTrailB, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageB, 0.06, (double)feePackageB);
		}
		if (x == 3) {
			Animal newAnimal(animalNewName, newSize, newPet);

			packageB.setUpPackageB(newAnimal, feePackageB, freeTrailB);

			Package yourPackage(feePackageB, freeTrailB, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageB, 0.06, (double)feePackageB);
		}

	}
	if (PackageChoice == "c" || PackageChoice == "C") {

		if (x == 1) {
			Animal animal(animalName, size, pet);

			packageC.setUpPackageC(animal, feePackageC, freeTrailC);

			Package yourPackage(feePackageC, freeTrailC, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageC, 0.06, (double)feePackageC);
		}
		if (x == 3) {
			Animal newAnimal(animalNewName, newSize, newPet);

			packageC.setUpPackageC(newAnimal, feePackageC, freeTrailC);

			Package yourPackage(feePackageC, freeTrailC, PackageChoice);
			cout << yourPackage;
			totalFee = totalBill((double)feePackageC, 0.06, (double)feePackageC);
		}
	}

	cout << "\n--------------------------------------\n";

	PayBill payBill;
	ptrPayBill = &payBill;

	ptrPayBill->disPlayPayBill();

	cout << " Enter the way you want to pay: ";
	cin >> userPayChoice;

	tryAgain = true;
	while (tryAgain) {
		try
		{
			ptrPayBill->setUserPayChoice(userPayChoice);
			tryAgain = false;
		}
		catch (PayBill::InvalidChoice) {
			cout << " we have problem with your choice. Please enter again: ";
			cin >> userPayChoice;
		}
	}

	if (ptrPayBill->getUserPayChoice() == 1) {

		cin >> payBill;
		userAmount = ptrPayBill->getUserAmount();

		while (userAmount < totalFee) {

			reMain = remain(totalFee, userAmount);
			cout << " Your payment is processing...  \n\n"
				<< " you have to pay $" << reMain << " more to complete your payment.";
			totalFee = reMain;

			cin >> payBill;
			userAmount = ptrPayBill->getUserAmount();

		}
		if (userAmount >= totalFee) {
			cout
				<< " Your payment has been done.  \n"
				<< " Your change is: $" << change(totalFee, userAmount) << " \n"
				<< " Thank you and see you next time \n";
		}
	}
	else
		if (ptrPayBill->getUserPayChoice() == 2 || ptrPayBill->getUserPayChoice() == 3) {
			cout << "\n insert your card. \n"
				<< "... \n";
		}


	system("pause");
	return 0;
}

int getvalidOption(Option &o) { // get the valid option 

	int num;
	cout << "\n Enter the option you want: ";
	cin >> num;

	bool tryAgain = true;

	while (tryAgain) {
		try
		{
			o.setoptionChoice(num);
			tryAgain = false;
		}
		catch (Option::InvalidOption) {
			cout << " Enter the valid option ( 1, 2, 3). Try again: ";
			cin >> num;
		}
	}

	return num;
}