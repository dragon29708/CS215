/*
--------------------------------------------------------------------
                        CS215-401 LAB 2
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/9/2019
Description: Write a complete C++ program to calculate an hourly
worker’s pay stub. The program should ask the user to enter their
first name, last name, hours worked and pay rate.
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const double ss_tax = 0.03, state_tax = 0.06, fed_tax = 0.07;

int main() {
	// Declare variables.
	string first_name, last_name;
	double hours, pay_rate, gross_pay, state_payment, fed_payment, ss_payment, net_pay;
	// Print display logo.
	cout << "+------------------------------------------+\n";
	cout << "|           PAYROLL CALCULATOR             |\n";
	cout << "|     By: Andrew Cassidy  Section: 401     |\n";
	cout << "+------------------------------------------+\n";
	// Get first name, last name, hours worked and pay rate from user.
	cout << "Enter first name:   "; cin >> first_name;
	cout << "Enter last name:    "; cin >> last_name;
	cout << "Enter hours worked: "; cin >> hours;
	cout << "Enter pay rate:     "; cin >> pay_rate;
	// Calculate gross pay, state tax, fed tax, ss tax and net pay.
	gross_pay = hours * pay_rate;
	state_payment = state_tax * gross_pay;
	fed_payment = fed_tax * gross_pay;
	ss_payment = ss_tax * gross_pay;
	net_pay = gross_pay - (state_payment + fed_payment + ss_payment);
	// Print out pay stub and align the printed numbers.
	cout << setprecision(2)<< fixed;
	cout << "\nName:     " << last_name << ", " << first_name << endl;
	cout << "Gross Pay $ " << setw(7) << gross_pay << endl;
	cout << "State Tax $ " << setw(7) << state_payment << endl;
	cout << "Fed Tax   $ " << setw(7) << fed_payment << endl;
	cout << "SS Tax    $ " << setw(7) << ss_payment << endl;
	cout << "Net Pay   $ " << setw(7) << net_pay << endl;
	cout << "\n";
	// Ending statements.
	system("pause");
	return 0;
}
