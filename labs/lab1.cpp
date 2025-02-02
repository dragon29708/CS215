//--------------------------------------------------------------------
//                        CS215-401 LAB 1
//--------------------------------------------------------------------
// Author: Andrew Cassidy
// Date: 9/5/2019
// Description: My first C++ program. It does arithmetic on two numbers.
//--------------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
	//
	cout << "                 _                   \n";
	cout <<	"	        | |                  \n";
	cout << "  __ _ _ __   __| |_ __ _____      __\n";
	cout <<	" / _` | '_ \\ / _` | '__/ _ \\ \\ /\\ / /\n";
	cout <<	"| (_| | | | | (_| | | |  __/\\ V  V /\n";
	cout << " \\__,_|_| |_|\\__,_|_|  \\___| \\_/\\_/\n\n";
	// Title Box.
	cout << "+-------------------------------+\n";
	cout << "|           Number Fun!         |\n";
	cout << "|       By: Andrew Cassidy      |\n";
	cout << "+-------------------------------+\n";
	// Initialize num1 and num2 for user input.
	int num1;
	int num2;
	// Prompt user to input two numbers.
	cout << "Enter a number: "; cin >> num1;
	cout << "Enter another:  "; cin >> num2; cout << endl;
	// Calculate sum, diff, prod, int qout and float quot.
	int sum = num1 + num2;
	int diff = num1 - num2;
	int prod = num1 * num2;
	int int_quot = num1 / num2;
	float float_quot = static_cast<double>(num1) / num2;
	// Calculate and print sum, diff, prod, int qout and float qout.
	cout << "Sum:            " << sum << endl;
	cout << "Difference:     " << diff << endl;
	cout << "Product:        " << prod << endl;
	cout << "Int Quotient:   " << int_quot << endl;
	cout << "Float Quotient: " << float_quot << endl;
	// End statements.
	system("Pause");
	return 0;
}
