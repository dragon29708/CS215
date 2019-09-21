/*
--------------------------------------------------------------------
       					CS215-401 Program 1
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/17/2019
Description: A program that simulates a coffee machine.
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<Windows.h>

using namespace std;

int main() {
	// Declaring variables.
	const double price_coffee = 0.15, price_latte = 0.25, price_mocha = 0.30, tax = 0.06;
	const int sleepMSecs = 2000;
	unsigned int tank_coffee, tank_latte, tank_mocha, drink_size;
	string input_raw = "";
	char input_usable;
	bool input_bool = false, drink_bool = false, payment_bool = false;
	double total_price, amount_paid;
	// While the escape char isn't inputted.
	while (input_raw != "!") {
		// Print out logo.
		cout << "+----------------------------------+\n";
		cout << "|           CAFE' VEND             |\n";
		cout << "|       by: Andrew Cassidy         |\n";
		cout << "+----------------------------------+\n";
		// Start up menu for mantenance worker.
		cout << "STARTUP: Enter tank levels" << endl;
		cout << setw(10) << "Coffee Tank: "; cin >> tank_coffee;
		cout << setw(10) << "Latte Tank:  "; cin >> tank_latte;
		cout << setw(10) << "Mocha Tank:  "; cin >> tank_mocha;
		cout << endl;
		// Print out menu.
		cout << "PLEASE SELECT YOUR BEVERAGE!" << endl;
		cout << "C. Coffee   $ 0.15 per oz." << endl;
		cout << "L. Latte    $ 0.25 per oz." << endl;
		cout << "M. Mocha    $ 0.30 per oz." << endl;
		// Get drink from user.
		// USE THE FIND() FUNCTION IN <STRING>
		// string::npos
		cout << "===> "; cin >> input_raw;
		while (input_bool != true) {
			input_usable = toupper(input_raw[0]);
			if ((input_usable == 'C') && (tank_coffee != 0))
				input_bool = true;
			else if ((input_usable == 'L') && (tank_latte != 0))
				input_bool = true;
			else if ((input_usable == 'M') && (tank_mocha != 0))
				input_bool = true;
			else {
				cout << "Invalid selection! Try again!" << endl;
				cout << "===> "; cin >> input_raw;
			}
		}
		// Get amount (oz) from user.
		cout << "Number of ounces (9-18): "; cin >> drink_size;
		while (drink_bool != true) {
			if ((drink_size >= 9) && (drink_size <= 18))
				drink_bool = true;
			else {
				cout << "Invalid entry!" << endl;
				cout << "Number of ounces (9-18): "; cin >> drink_size;
			}
		}
		// Calculate total price.
		if (input_usable == 'C') {
			total_price = price_coffee * drink_size + (price_coffee * drink_size) * tax;
			total_price = round(total_price * 100) / 100;
		}
		else if (input_usable == 'L') {
			total_price = price_latte * drink_size + (price_latte * drink_size) * tax;
			total_price = round(total_price * 100) / 100;
		}
		else {
			total_price = price_mocha * drink_size + (price_mocha * drink_size) * tax;
			total_price = round(total_price * 100) / 100;
		}
		// Display total price and ask for user to pay.
		cout << "Total Price:       $ " << total_price << endl;
		cout << "Enter amount paid: $ "; cin >> amount_paid;
		// Payment input verification.
		while (payment_bool != true) {
			if (total_price > amount_paid) {
				cout << "That is not enough! Please try again." << endl;
				cout << "Enter amount paid: $ "; cin >> amount_paid;
			}
			else
				payment_bool = true;
		}
		// Print the change, thank user for purchase and start the brewing!
		cout << "Your change $ " << amount_paid - total_price << " falls out of the machine on the floor." << endl;
		if (input_usable == 'C')
			cout << "Thank you! Your Coffee will now be brewed!" << endl;
		else if (input_usable == 'L')
			cout << "Thank you! Your Latte will now be brewed!" << endl;
		else
			cout << "Thank you! Your Mocha will now be brewed!" << endl;
		// Display the brewing happening.
		cout << endl << "A cup drops out of the machine below the Mocha spigot." << endl;
	}
	// Ending statements.
	system("pause");
	return 0;
}
