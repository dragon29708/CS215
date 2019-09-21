/*
--------------------------------------------------------------------
       					CS215-401 Lab 3
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/17/2019
Description: Create a nxn box of symbols where n and the symbol are
inputted by the user.
--------------------------------------------------------------------
*/

#include<iostream>

using namespace std;

int main() {
	char selection, symbol;
	bool selection_ok = false;
	int size;
	// Program title.
	cout << "+--------------------------------------+" << endl;
	cout << "|              Box Maker               |" << endl;
	cout << "+--------------------------------------+" << endl;
	// Print character options.
	cout << "Box Characters:" << endl;
	cout << "S - Star" << endl;
	cout << "D - Dollar" << endl;
	cout << "B - Backslash" << endl;
	// Get selection and validate it.
	cout << "\nEnter your selection: "; cin >> selection;
	while (selection_ok != true) {
		if (toupper(selection) == 'S')
			selection_ok = true;
		else if (toupper(selection) == 'D')
			selection_ok = true;
		else if (toupper(selection) == 'B')
			selection_ok = true;
		else {
			cout << "Invalid entry. Enter S, D or B!" << endl;
			cout << "Enter your selection: "; cin >> selection;
		}
	}
	// Get size and validate it.
	cout << "\nEnter size of box (3-7): "; cin >> size;
	while ((size > 7) || (size < 3)) {
		cout << "Invalid entry. Enter a number 3-7!" << endl;
		cout << "Enter size of box (3-7): "; cin >> size;
	}
	cout << endl;
	// Decide on which symbol to use.
	if (toupper(selection) == 'S')
		symbol = '*';
	else if (toupper(selection) == 'D')
		symbol = '$';
	else
		symbol = '\\';
	// Print out box.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << symbol << ' ';
		}
		cout << endl;
	}
	// Ending statements.
	cout << endl;
	system("pause");
	return 0;
}
