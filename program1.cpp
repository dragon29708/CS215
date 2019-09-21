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
	const double price_coffee = 0.15, price_latte = 0.25, price_mocha = 0.30, tax_rate = 0.06;
	const int sleepMSecs = 2000;
	int tank_coffee = 18, tank_latte = 18, tank_mocha = 18, drinks_sold = 0, drink_size;
	int ounces_bought_coffee = 0, ounces_bought_latte = 0, ounces_bought_mocha = 0;
	string input_raw = "";
	char input_usable;
	double total_price, amount_paid, total_tax, subtotal, change, total_coffee = 0.0, total_latte = 0.0, total_mocha = 0.0;
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
	// While the escape char isn't inputted.
	while (true) {
		// Bool variables that need to be re-initialized each interation of while loop.
		bool input_bool = false, drink_bool = false, payment_bool = false;
		// Print out menu.
		if ((tank_coffee < 18) && (tank_latte < 18) && (tank_mocha))
			cout << "ALL DRINK TANKS EMPTY. PLEASE REFILL!" << endl;
		else
			cout << "PLEASE SELECT YOUR BEVERAGE!" << endl;
		if (tank_coffee >= 18)
			cout << "C. Coffee   $ 0.15 per oz." << endl;
		if (tank_latte >= 18)
			cout << "L. Latte    $ 0.25 per oz." << endl;
		if (tank_mocha >= 18)
			cout << "M. Mocha    $ 0.30 per oz." << endl;
		// Get drink from user.
		cout << "===> "; cin >> input_raw;
		if (input_raw[0] == '!')
			break;
		while (input_bool != true) {
			input_usable = toupper(input_raw[0]);
			if ((input_usable == 'C') && (tank_coffee >= 18))
				input_bool = true;
			else if ((input_usable == 'L') && (tank_latte >= 18))
				input_bool = true;
			else if ((input_usable == 'M') && (tank_mocha >= 18))
				input_bool = true;
			else {
				cout << "Invalid selection! Try again!" << endl;
				cout << "===> "; cin >> input_raw;
			}
		}
		// Get amount (oz) from user.
		cout << "Number of ounces (9-18): "; cin >> drink_size;
		while (drink_bool != true) {
			if ((drink_size >= 9) && (drink_size <= 18)) {
				drink_bool = true;
				if (input_usable == 'C') {
					tank_coffee -= drink_size;
					ounces_bought_coffee += drink_size;
				}
				else if (input_usable == 'L') {
					tank_latte -= drink_size;
					ounces_bought_latte += drink_size;
				}
				else {
					tank_mocha -= drink_size;
					ounces_bought_mocha += drink_size;
				}
			}
			else {
				cout << "Invalid entry!" << endl;
				cout << "Number of ounces (9-18): "; cin >> drink_size;
			}
		}
		// Calculate subtotal, tax amount and total price.
		if (input_usable == 'C')
			subtotal = price_coffee * drink_size;
		else if (input_usable == 'L')
			subtotal = price_latte * drink_size;
		else
			subtotal = price_mocha * drink_size;
		total_tax = subtotal * tax_rate;
		total_price = round((subtotal + total_tax) * 100) / 100;
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
		// Print the change and thank user for purchase.
		change = amount_paid - total_price;
		cout << "Your change $ " << change << " falls out of the machine on the floor." << endl;
		if (input_usable == 'C') {
			cout << "Thank you! Your Coffee will now be brewed!" << endl;
			total_coffee += subtotal;
		}
		else if (input_usable == 'L') {
			cout << "Thank you! Your Latte will now be brewed!" << endl;
			total_latte += subtotal;
		}
		else {
			cout << "Thank you! Your Mocha will now be brewed!" << endl;
			total_mocha += subtotal;
		}
		// Display the brewing happening.
		Sleep(sleepMSecs);
		cout << endl << "A cup drops out of the machine below the Mocha spigot." << endl;
		Sleep(sleepMSecs);
		for (int i = 3; i <= drink_size; i += 3) {
			cout << " " << i << " ounces dispenced..." << endl;
			Sleep(sleepMSecs);
		}
		if ((drink_size % 3) != 0) {
			cout << " " << drink_size << " ounces dispenced..." << endl;
			Sleep(sleepMSecs);
		}
		// Make sure all numbers have two digits after the decimal.
		cout << setprecision(2) << fixed;
		// Display receipt.
		if (input_usable == 'C') {
			cout << endl << "Your Coffee is ready! Here is your receipt!" << endl;
			cout << "Beverage:       Coffee" << endl;
			cout << "Ounces:         " << drink_size << endl;
			cout << "Price per Oz: $ " << price_coffee << endl;
		}
		else if (input_usable == 'L') {
			cout << endl << "Your Latte is ready! Here is your receipt!" << endl;
			cout << "Beverage:       Latte" << endl;
			cout << "Ounces:         " << drink_size << endl;
			cout << "Price per Oz: $ " << price_latte << endl;
		}
		else {
			cout << endl << "Your Mocha is ready! Here is your receipt!" << endl;
			cout << "Beverage:       Mocha" << endl;
			cout << "Ounces:         " << drink_size << endl;
			cout << "Price per Oz: $ " << price_mocha << endl;
		}
		cout << "Sub Total:    $ " << subtotal << endl;
		cout << "Tax:          $ " << total_tax << endl;
		cout << "Total:        $ " << total_price << endl;
		cout << "Amount Paid:  $ " << amount_paid << endl;
		cout << "Change:       $ " << change << endl;
		// Add 1 to drinks sold per interation of the while loop.
		drinks_sold++;
		// Re-run program.
		system("pause");
		cout << endl << endl;
	}
	// Shutdown report.
	cout << endl << "SHUTDOWN: Totals sold: " << drinks_sold << endl;
	cout << "BEVERAGE  OUNCES  TOTAL SOLD  LEFT IN TANK" << endl;
	cout << "--------  ------  ----------  ------------" << endl;
	cout << "Coffee        " << ounces_bought_coffee << "   $    " << total_coffee << "               " << tank_coffee << endl;
	cout << "Latte         " << ounces_bought_latte <<  "   $    " << total_latte << "               " << tank_latte << endl;
	cout << "Mocha         " << ounces_bought_mocha <<  "   $    " << total_mocha << "               " << tank_mocha << endl;
	cout << "TOTAL         " << "    $" << total_coffee + total_latte + total_mocha << endl;
	// Ending statements.
	system("pause");
	return 0;
}
