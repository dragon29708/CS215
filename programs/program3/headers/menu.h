//-------------------------------------------------------------------
//                      menu Class Decleration
//-------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>

using namespace std;

const int MAX_NUM_OPTIONS = 10;

class menu {
public:
    // constructor
    menu();
    // sets
    void setTitle(string newTitle);
    void setErrorMessage(string newErrorMessage);
    // addOption
    void addOption(char newOption, string newOptionDescription);
    // doMenu
    char doMenu();
    // validOption
    bool validOption(char checkChar);
private:
    char menuOptions[MAX_NUM_OPTIONS];
    string menuOptionDescriptions[MAX_NUM_OPTIONS];
    int numOptions;
    string title;
    string errorMessage;
};
