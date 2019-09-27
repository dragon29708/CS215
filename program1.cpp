/*
--------------------------------------------------------------------
						CS215-401 Program 1
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/17/2019
Description: A program that simulates a coffee machine.
Assistance: I received help from no one.
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<Windows.h>

using namespace std;

// Global constants.
const double coffeePrice = 0.15, lattePrice = 0.25, mochaPrice = 0.30, taxRate = 0.06;
const int sleepMSecs = 2000;

int main() {
	// Tank size variables per drink type
	int coffeeTank = 18, latteTank = 18, mochaTank = 18;
	// Size of drink user inputs.
	int drinkSize;
	// Ounces of drink type bought.
	int ozBoughtCoffee = 0, ozBoughtLatte = 0, ozBoughtMocha = 0;
	// Choice user inputs for drink.
	string drinkChoice = "";
	// Char taken from first char in drinkChoice. Used for knowing which drink user wants.
	char drinkChoiceChar = ' ';
	// Variables used for money, receipt, etc.
	double totalPrice, amountPaid, totalTax, subtotal, change;
	// Total amount of drink type sold.
	double coffeeSold = 0.0, latteSold = 0.0, mochaSold = 0.0;

	// Print out logo.
	cout << "+----------------------------------+\n";
	cout << "|           CAFE' VEND             |\n";
	cout << "|       by: Andrew Cassidy         |\n";
	cout << "+----------------------------------+\n";

	// Start up menu for mantenance worker.
	cout << "STARTUP: Enter tank levels" << endl;
	cout << setw(10) << "Coffee Tank: "; cin >> coffeeTank;
	cout << setw(10) << "Latte Tank:  "; cin >> latteTank;
	cout << setw(10) << "Mocha Tank:  "; cin >> mochaTank;
	cout << endl;

	// While the escape char isn't inputted.
	while (drinkChoiceChar != '!') {

		// Bool variables that need to be re-initialized each interation of while loop.
		bool input_bool = false, drink_bool = false, payment_bool = false;
		// Print out menu.
		if ((coffeeTank < 18) && (latteTank < 18) && (mochaTank))
			cout << "ALL DRINK TANKS EMPTY. PLEASE REFILL!" << endl;
		else
			cout << "PLEASE SELECT YOUR BEVERAGE!" << endl;
		if (coffeeTank >= 18)
			cout << "C. Coffee   $ 0.15 per oz." << endl;
		if (latteTank >= 18)
			cout << "L. Latte    $ 0.25 per oz." << endl;
		if (mochaTank >= 18)
			cout << "M. Mocha    $ 0.30 per oz." << endl;

		// Get drink from user.
		cout << "===> "; cin >> drinkChoice;
		while (input_bool != true) {
			drinkChoiceChar = toupper(drinkChoice[0]);
			if ((drinkChoiceChar == 'C') && (coffeeTank >= 18))
				input_bool = true;
			else if ((drinkChoiceChar == 'L') && (latteTank >= 18))
				input_bool = true;
			else if ((drinkChoiceChar == 'M') && (mochaTank >= 18))
				input_bool = true;
			else if (drinkChoiceChar == '!')
				input_bool = true;
			else {
				cout << "Invalid selection! Try again!" << endl;
				cout << "===> "; cin >> drinkChoice;
			}
		}

		if (drinkChoiceChar != '!') {
			// Get amount (oz) from user.
			cout << "Number of ounces (9-18): "; cin >> drinkSize;
			while (drink_bool != true) {
				if ((drinkSize >= 9) && (drinkSize <= 18)) {
					drink_bool = true;
					if (drinkChoiceChar == 'C') {
						coffeeTank -= drinkSize;
						ozBoughtCoffee += drinkSize;
					}
					else if (drinkChoiceChar == 'L') {
						latteTank -= drinkSize;
						ozBoughtLatte += drinkSize;
					}
					else {
						mochaTank -= drinkSize;
						ozBoughtMocha += drinkSize;
					}
				}
				else {
					cout << "Invalid entry!" << endl;
					cout << "Number of ounces (9-18): "; cin >> drinkSize;
				}
			}

			// Calculate subtotal, tax amount and total price.
			if (drinkChoiceChar == 'C')
				subtotal = coffeePrice * drinkSize;
			else if (drinkChoiceChar == 'L')
				subtotal = lattePrice * drinkSize;
			else
				subtotal = mochaPrice * drinkSize;
			totalTax = subtotal * taxRate;
			totalPrice = round((subtotal + totalTax) * 100) / 100;

			// Display total price and ask for user to pay.
			cout << "Total Price:       $ " << setprecision(2) << fixed << totalPrice << endl;
			cout << "Enter amount paid: $ "; cin >> amountPaid;

			// Payment input verification.
			while (payment_bool != true) {
				if (totalPrice > amountPaid) {
					cout << "That is not enough! Please try again." << endl;
					cout << "Enter amount paid: $ "; cin >> amountPaid;
				}
				else
					payment_bool = true;
			}

			// Make sure all numbers have two digits after the decimal.
			cout << setprecision(2) << fixed;

			// Print the change and thank user for purchase.
			change = amountPaid - totalPrice;
			cout << "Your change $ " << change << " falls out of the machine on the floor." << endl;
			if (drinkChoiceChar == 'C') {
				cout << "Thank you! Your Coffee will now be brewed!" << endl;
				coffeeSold += subtotal;
			}
			else if (drinkChoiceChar == 'L') {
				cout << "Thank you! Your Latte will now be brewed!" << endl;
				latteSold += subtotal;
			}
			else {
				cout << "Thank you! Your Mocha will now be brewed!" << endl;
				mochaSold += subtotal;
			}

			// Display the brewing happening.
			Sleep(sleepMSecs);
			cout << endl << "A cup drops out of the machine below the Mocha spigot." << endl;
			Sleep(sleepMSecs);
			for (int i = 3; i <= drinkSize; i += 3) {
				cout << setw(2) << i << " ounces dispenced..." << endl;
				Sleep(sleepMSecs);
			}
			if ((drinkSize % 3) != 0) {
				cout << setw(2) << drinkSize << " ounces dispenced..." << endl;
				Sleep(sleepMSecs);
			}

			// Display receipt.
			if (drinkChoiceChar == 'C') {
				cout << endl << "Your Coffee is ready! Here is your receipt!" << endl;
				cout << "Beverage:       Coffee" << endl;
				cout << "Ounces:         " << drinkSize << endl;
				cout << "Price per Oz: $ " << coffeePrice << endl;
			}
			else if (drinkChoiceChar == 'L') {
				cout << endl << "Your Latte is ready! Here is your receipt!" << endl;
				cout << "Beverage:       Latte" << endl;
				cout << "Ounces:         " << drinkSize << endl;
				cout << "Price per Oz: $ " << lattePrice << endl;
			}
			else {
				cout << endl << "Your Mocha is ready! Here is your receipt!" << endl;
				cout << "Beverage:       Mocha" << endl;
				cout << "Ounces:         " << drinkSize << endl;
				cout << "Price per Oz: $ " << mochaPrice << endl;
			}
			cout << "Sub Total:    $ " << subtotal << endl;
			cout << "Tax:          $ " << totalTax << endl;
			cout << "Total:        $ " << totalPrice << endl;
			cout << "Amount Paid:  $ " << amountPaid << endl;
			cout << "Change:       $ " << change << endl;

			// Re-run program.
			system("pause");
			cout << endl << endl;
		}
	}

	// Shutdown report.
	cout << endl << "SHUTDOWN: Totals sold: " << endl;
	cout << "BEVERAGE  OUNCES  TOTAL SOLD  LEFT IN TANK" << endl;
	cout << "--------  ------  ----------  ------------" << endl;
	cout << setw(8) << left << "Coffee" << "  ";
	cout << setw(6) << right << ozBoughtCoffee;
	cout << "  $" << setw(8) << right << coffeeSold;
	cout << setw(7) << " " << setw(3) << coffeeTank << endl;
	cout << setw(8) << left << "Latte" << "  ";
	cout << setw(6) << right << ozBoughtLatte;
	cout << "  $" << setw(8) << right << latteSold;
	cout << setw(7) << " " << setw(3) << latteTank << endl;
	cout << setw(8) << left << "Mocha" << "  ";
	cout << setw(6) << right << ozBoughtMocha;
	cout << "  $" << setw(8) << right << mochaSold;
	cout << setw(7) << " " << setw(3) << mochaTank << endl;
	cout << setw(8) << left << "TOTAL" << "  ";
	cout << setw(9) << right << "$" << setw(8) << right << coffeeSold + latteSold + mochaSold << endl;

	// Ending statements.
	system("pause");
	return 0;
}
