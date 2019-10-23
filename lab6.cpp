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
    return myFrac.num / static_cast<float>((myFrac.den));
} // DecimalValue()




//------------------------------------------------------------------
//                            Main
//------------------------------------------------------------------
int main() {

    // get fraction from user
    frac myFrac = AskFraction();

    // get decimal value of fraction
    cout << DecimalValue(myFrac) << endl;

    system("pause");
    return 0;
}
