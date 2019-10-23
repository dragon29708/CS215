/*
--------------------------------------------------------------------
                          CS215-401 Lab 6
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 10/20/2019
Description: Create a set a functions that all take 2 integers as
arguments and does their sum, decimal value, multiplication,
division etc.
--------------------------------------------------------------------
*/

#include<iostream>
#include<iomanip>

using namespace std;


// fraction object declaration
struct frac {
    int num;    // numerator
    int den;    // denominator
};


//------------------------------------------------------------------
//                            AskFraction
//------------------------------------------------------------------
frac AskFraction() {
    frac myFrac;
    myFrac.num = 0;
    myFrac.den = 0;

    // get info from user for myFrac
    cout << "Enter numerator: "; cin >> myFrac.num;

    cout << "Enter denominator: "; cin >> myFrac.den;
    // input validation for denominator
    while (myFrac.den <= 0) {
        cout << "Invalid entry. Enter an integer > 0\n";
        cout << "Enter denominator: "; cin >> myFrac.den;
    }

    // return valid fraction
    return myFrac;
} // AskFraction()


//------------------------------------------------------------------
//                            DecimalValue
//------------------------------------------------------------------
double DecimalValue(frac myFrac) {
    // return the decimal value of the inputted fraction
    return myFrac.num / static_cast<float>((myFrac.den));
} // DecimalValue()


//------------------------------------------------------------------
//                            PrintFraction
//------------------------------------------------------------------
void PrintFraction(frac myFrac) {
    // the numerator (use a width of 3)
    cout << setw(3) << right << myFrac.num << endl;

    // four dashes, an equal sign, and the decimal value; invoke DecimalValue()
    cout << "----  = " << DecimalValue(myFrac) << endl;

    // the denominator (use a width of 3)
    cout << setw(3) << right << myFrac.den << endl;
} // PrintFraction()


//------------------------------------------------------------------
//                            Multiply
//------------------------------------------------------------------
double Multiply(frac frac1, frac frac2) {
    // calculate product of frac1 and frac 2
    product = DecimalValue(frac1) * DecimalValue(frac2);

    // return product
    return product;
} // Multiply()


//------------------------------------------------------------------
//                            main
//------------------------------------------------------------------
int main() {

    // get fraction from user
    frac myFrac1 = AskFraction();

    // print out fraction
    PrintFraction(myFrac);

    system("pause");
    return 0;
} // main()
