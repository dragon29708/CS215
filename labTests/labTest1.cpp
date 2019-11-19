/*
--------------------------------------------------------------------
						 CS 215 - Lab Exam 1 - A
							 Andrew Cassidy
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main() {

// Question 1 begin.
	// Q1 variables.
	int coinValue;
	bool coinOk = false;
	cout << "\nQuestion 1:\n";
	cout << "Enter coin value <1,5,10,25,50>: "; cin >> coinValue;

	// Input validation.
	while (coinOk == false) {
		if ((coinValue == 1) || (coinValue == 5) || (coinValue == 10) || (coinValue == 25) || (coinValue == 50))
		coinOk = true;
		else {
			cout << "Invalid entry!\n";
			cout << "Enter coin value <1,5,10,25,50>: "; cin >> coinValue;
		}
	}
	if (coinValue == 1)
		cout << "Penny\n";
	else if (coinValue == 5)
		cout << "Nickel\n";
	else if (coinValue == 10)
		cout << "Dime\n";
	else if (coinValue == 25)
		cout << "Quarter\n";
	else
		cout << "Half Dollar\n";


// Question 2 begin.
	// Q2 variables.
	int numItems;
	string name;
	float price;
	float cheapPrice;
	string cheapItem;
	float subTotal = 0.00;
	const float taxRate = 0.06;
	float tax;
	float total;

	cout << "\nQuestion 2:\n";
	cout << "How many items? "; cin >> numItems;
	cout << "Enter item 1 name: "; cin >> name;
	cout << "Enter item 1 price: "; cin >> price;
	cheapPrice = price;
	cheapItem = name;
	// Add up the money.
	subTotal += price;
	for (int i = 2; i <= numItems; i++) {

		cout << "Enter item " << i << " name: "; cin >> name;
		cout << "Enter item " << i << " price: "; cin >> price;

		// Add up the money.
		subTotal += price;

		// Find cheapest item.
		if (price < cheapPrice) {
			cheapPrice = price;
			cheapItem = name;
		}
	}
	cout << setprecision(2) << fixed;
	cout << "Cheapest Item: " << cheapItem << " $ " << cheapPrice << endl;

	if (subTotal >= 10.0) {
		cout << "You get the Hat for free!\n";
		subTotal -= cheapPrice;
	}
	// Calc tax.
	tax = subTotal * taxRate;

	// Calc total.
	total = subTotal + tax;

	// Print report.
	cout << "Sub Total: $" << setw(6) << right << subTotal << endl;
	cout << "Tax:       $" << setw(6) << right << tax << endl;
	cout << "Total:     $" << setw(6) << right << total << endl;

// Question 3 begin.
	// Q3 variables.
	string readFile;
	int numReadings;
	string date;
	float temp;
	float highTemp = 0.0;
	float avgTemp;
	float sumTemps = 0.0;
	string highDate;
	cout << "\nQuestion 3:\n";

	// Build my read file object for reading a file.
	ifstream fin;

	// Get input and file from user.
	cout << "Enter input file name: "; cin >> readFile;

	fin.open(readFile);

	// Check if file can be opened.
	if (fin.fail()) {
		// File cannot be opened. Program exits.
		cout << "Unable to open file!" << endl;
		system("Pause");
		return 0;
	}


	fin >> numReadings;
	cout << "Date   Temp" << endl;
	cout << "------ -----" << endl;
	for (int i = 0; i < numReadings; i++) {
		fin >> date >> temp;

		cout << setw(6) << left << date << setw(6) << right << temp << endl;

		if (temp > highTemp) {
			highTemp = temp;
			highDate = date;
		}

		sumTemps += temp;
	}

	avgTemp = sumTemps / static_cast<float>(numReadings);

	// Close readFile.
	fin.close();

	cout << "Number of readings:  " << numReadings << endl;
	cout << "Highest temperature: " << highTemp << " on " << highDate << endl;
	cout << "Average temperature: " << avgTemp << endl;


	system("Pause");
	return 0;
}