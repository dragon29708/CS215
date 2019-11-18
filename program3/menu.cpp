//-------------------------------------------------------------------
//                      menu Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
menu::menu() {
    // set strings to "" and numbers to 0
	for (int i = 0; i < numOptions; i++) {
		menuOptions[i] = ' ';
		menuOptionDescriptions[i] = "";
	}
    numOptions = 0;
    title = " ";
    errorMessage = " ";
}// menu()



//-------------------------------------------------------------------
//                               setTitle
//-------------------------------------------------------------------
void menu::setTitle(string newTitle) {
    title = newTitle;
}// setTitle()


//-------------------------------------------------------------------
//                               setErrorMessage
//-------------------------------------------------------------------
void menu::setErrorMessage(string newErrorMessage) {
    errorMessage = newErrorMessage;
}// setErrorMessage()



//-------------------------------------------------------------------
//                               addOption
//-------------------------------------------------------------------
void menu::addOption(char newOption, string newOptionDescription) {
	// if room for another menu option, add option char and description
	// to both char and description lists
    if (numOptions != MAX_NUM_OPTIONS) {
        menuOptions[numOptions] = newOption;
        menuOptionDescriptions[numOptions] = newOptionDescription;
		numOptions++;
    }
    else
        cout << "no room for more options\n";
}// addOption()


//-------------------------------------------------------------------
//                               validOption
//-------------------------------------------------------------------
bool menu::validOption(char checkChar) {
    // check for char in menuOptions array
    for (int i = 0; i < numOptions; i++) {
        if (menuOptions[i] == checkChar)
            return true;
    }

    // char wasnt found
    return false;
}// validOption()


//-------------------------------------------------------------------
//                               doMenu
//-------------------------------------------------------------------
char menu::doMenu() {
	// print title and options
    cout << title << endl;
	for (int i = 0; i < numOptions; i++) {
        cout << menuOptions[i] << " - " << menuOptionDescriptions[i] << endl;
    }

    // get options
    char option;
    cout << "Enter option: ";
    cin >> option;

    // captialize option
	option = toupper(option);

    // option validation
    while (!validOption(option)) {
        cout << "Invalid option! Try again!\n";
        cout << "Enter option: ";
        cin >> option;
        option = toupper(option);
    }

	return option;
}// doMenu()
