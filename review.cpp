// Programmer Duy Vo
// Date: 12/18/19

#include "review.h"
#include "option.h"
#include <fstream>
#include <iostream>
using namespace std;

ifstream readFile;
string line;

void Review::printout()
{
	readFile.open(fileName);
	while (getline(readFile, line)) {    // read every single line 
		cout << line << '\n';           // out put on the sreen 
	}
	readFile.close();
}
