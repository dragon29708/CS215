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
    cout << "Enter numerator:       "; cin >> myFrac.num;

    cout << "Enter denominator > 0: "; cin >> myFrac.den;
    // input validation for denominator
    while (myFrac.den <= 0) {
        cout << "Invalid entry. Enter an integer > 0\n";
        cout << "Enter denominator > 0: "; cin >> myFrac.den;
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
frac Multiply(frac frac1, frac frac2) {
    frac product;

    // numerator of product
    product.num = frac1.num * frac2.num;

    // denominator of product
    product.den = frac1.den * frac2.den;

    // return product
    return product;
} // Multiply()


//------------------------------------------------------------------
//                            Add
//------------------------------------------------------------------
frac Add(frac frac1, frac frac2) {
    frac sum;

    // if denominators are same
    if (frac1.den == frac2.den) {
        // add numerators and keep denominator the same
        sum.num = frac1.num + frac2.num;
        sum.den = frac1.den;
    }
    // if denominators are different
    else {
        // get the same denominator for adding
        frac1.num = frac1.num * frac2.den;
        frac2.num = frac2.num * frac1.den;
        frac1.den = frac1.den * frac2.den;
        frac2.den = frac2.den * frac1.den;

        // add numerators once denominators are same
        sum.num = frac1.num + frac2.num;
        sum.den = frac1.den;
    }

    // return sum
    return sum;
} // Add()


//------------------------------------------------------------------
//                            main
//------------------------------------------------------------------
int main() {

    // get fractions from user
    cout << "FRACTION 1:\n";
    frac myFrac1 = AskFraction();
    cout << endl << "FRACTION 2:\n";
    frac myFrac2 = AskFraction();

    // print out multiplication of two fractions
    cout << "PRODUCT:\n";
    PrintFraction(Multiply(myFrac1, myFrac2));

    // print out addition of two fractions
    cout << "\nSUM:\n";
    PrintFraction(Add(myFrac1, myFrac2));

    // print out product simplified
    cout << "\nPRODUCT SIMPLIFIED:\n";

    system("pause");
    return 0;
} // main()
