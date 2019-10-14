//----------------------------------------------------------------------------
//                               TEST.cpp
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//----------------------------------------------------------------------------
//                                 isValidOption
//----------------------------------------------------------------------------
// Modifies: nothing.
// Returns: true or false if option is valid or not.
//----------------------------------------------------------------------------
bool isValidOption(char option, string validOptions) {
    // Loop through validOptions string to validate option input.
    for (int i = 0; i < validOptions.length(); i++) {
        if (validOptions[i] == option)
            return true; // Return true if option is found in validOptions string.
    }
    return false; // option was not found in validOptions string.
} // isValidOption

void main() {

    cout << "Input: I, expecting true, got: " << isValidOption('I', "IOLX") << endl;
    cout << "Input: O, expecting true, got: " << isValidOption('O', "IOLX") << endl;
    cout << "Input: L, expecting true, got: " << isValidOption('L', "IOLX") << endl;
    cout << "Input: X, expecting true, got: " << isValidOption('X', "IOLX") << endl;

    cout << "Input: i, expecting false, got: " << isValidOption('i', "IOLX") << endl;
    cout << "Input: o, expecting false, got: " << isValidOption('o', "IOLX") << endl;
    cout << "Input: l, expecting false, got: " << isValidOption('l', "IOLX") << endl;
    cout << "Input: x, expecting false, got: " << isValidOption('x', "IOLX") << endl;

    cout << "Input: h, expecting false, got: " << isValidOption('h', "IOLX") << endl;
    cout << "Input: j, expecting false, got: " << isValidOption('j', "IOLX") << endl;
    cout << "Input: !, expecting false, got: " << isValidOption('!', "IOLX") << endl;
    cout << "Input: $, expecting false, got: " << isValidOption('$', "IOLX") << endl;
}
