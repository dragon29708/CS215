/*
--------------------------------------------------------------------
                CS215-401 Lab Exam 1 Practice - 401
                         Andrew Cassidy
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
    // Problem 1 variables.
    string stateInput;
    bool validInput;
    // Problem 2 variables.
    // Problem 3 variables.
    // Problem 4 variables.

    // Problem 1.
    cout << "Question 1:" << endl;
    // Get state name input.
    cout << "Enter state abbreviation <KY, OH, IN, TN, WV>: ";
    cin >> stateInput;
    while (validInput != true) {
        // stateInput input validation.
        stateInput = toupper(stateInput);
        if ((stateInput != "KY") & (stateInput != "OH") & (stateInput != "IN") & (stateInput != "TN") & (stateInput != "WV")) {
            cout << "Invalid entry!" << endl;
            cout << "Enter state abbreviation <KY, OH, IN, TN, WV>: ";
            cin >> stateInput;
            stateInput = toupper(stateInput);
        }
        else {
            // Print out state associated with abbreviation.
            if (stateInput == "KY") cout << "Kentucky" << endl;
            else if (stateInput == "OH") cout << "Ohio" << endl;
            else if (stateInput == "IN") cout << "Indiana" << endl;
            else if (stateInput == "TN") cout << "Tennessee" << endl;
            else cout << "West Virginia" << endl;
            // Get out of while loop.
            validInput = true;
        }
    }

    // Problem 2.
}
