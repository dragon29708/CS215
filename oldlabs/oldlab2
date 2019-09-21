/*Lab 2*/
#include<iostream>
using namespace std;

int main() {
	// Part 1.
	// Initialize the 3 inputted numbers.
	int num1, num2, num3;
	// Ask user to input 3 numbers.
	cout << "Enter number 1: "; cin >> num1;
	cout << "Enter number 2: "; cin >> num2;
	cout << "Enter number 3: "; cin >> num3;
	// Sort the 3 numbers.
	if (num1 < num2 && num2 < num3) {
		cout << "Sorted they are " << num1 << " " << num2 << " " << num3 << endl;
	}
	else if (num1 < num3 && num3 < num2) {
		cout << "Sorted they are " << num1 << " " << num3 << " " << num2 << endl;
	}
	else if (num2 < num1 && num1 < num3) {
		cout << "Sorted they are " << num2 << " " << num1 << " " << num3 << endl;
	}
	else if (num2 < num3 && num3 < num1) {
		cout << "Sorted they are " << num2 << " " << num3 << " " << num1 << endl;
	}
	else if (num3 < num1 && num1 < num2) {
		cout << "Sorted they are " << num3 << " " << num1 << " " << num2 << endl;
	}
	else {
		cout << "Sorted they are " << num3 << " " << num2 << " " << num1 << endl;
	}
	cout << "\n";
	// Part 2.
	// Initialize variables.
	string ap = "A. Aleppo Pepper", bp = "B. Banana Pepper", cp = "C. Cayenne Pepper", db = "D. Dragons Breath";
	char user_input;
	const int Aleppo = 30000, Banana = 1000, Cayenne = 40000, DragonsBreath = 2480000;
	// Print out menu and get input.
	cout << ap << endl; 
	cout << bp << endl; 
	cout << cp << endl; 
	cout << db << endl;
	cout << "Enter a letter to choose a pepper: ";
	cin >> user_input;
	// Print out the heat of the inputted pepper.
	if (user_input == 'a' || user_input == 'A') {
		cout << "That's " << Aleppo << " Scovilles of heat!" << endl;
	}
	else if (user_input == 'b' || user_input == 'B') {
		cout << "That's " << Banana << " Scovilles of heat!" << endl;
	}
	else if (user_input == 'c' || user_input == 'C') {
		cout << "That's " << Cayenne << " Scovilles of heat!" << endl;
	}
	else if (user_input == 'd' || user_input == 'D') {
		cout << "That's " << DragonsBreath << " Scovilles of heat!" << endl;
	}
	else {
		cout << "That pepper is not on the list" << endl;
	}
	// End statements.
	system("Pause");
	return 0;
	// calisse loves herself
}
