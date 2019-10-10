/*
--------------------------------------------------------------------
                         CS215-401 Lab 5
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 10/10/2019
Description: Friends list app.
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>


using namespace std;

const int MAX_FRIENDS = 5;
struct afriend {
    string name;
    string phone;
    string email;
};

int main() {
    // Variables.
    int numFriends;
    string input;
    int editNum;

    // Create list of objects of type afriend.
    afriend list[MAX_FRIENDS];

    // Build my read file object for reading a file.
    ifstream fin;
    fin.open("friends.txt");
    // Exit app if file doesn't open.
    if (fin.fail()) {
        // File cannot be opened. Program exits.
        cout << "File friends.txt not found.\n";
        system("Pause");
        return 0;
    }

    fin >> numFriends;
    // Populate list w/ contents of file.
    for (int i = 0; i < numFriends; i++) {
        fin >> list[i].name;
        fin >> list[i].phone;
        fin >> list[i].email;
    }

    while (input != "X") {
        // Menu.
        cout << "--------------------- Friend List -----------------\n";
        cout << "Num Name            Phone        Email             \n";
        cout << "--- --------------- ------------ ------------------\n";
        for (int j = 0; j < numFriends; j++) {
            cout << setw(3) << right << j << " ";
            cout << setw(15) << left << list[j].name << " ";
            cout << setw(12) << list[j].phone << " ";
            cout << setw(18) << left << list[j].email;
            cout << endl;
        }
        cout << "\n---------------------------------------------------\n";
        cout << "Options: A=Add  E=Edit  X=Exit\n";
        cout << "Enter A, E or X: "; cin >> input;


        input = toupper(input[0]);
        if (input == "A" || input == "E" || input == "X") {
            // Add.
            if ((input == "A") && (numFriends < MAX_FRIENDS)) {
                cout << "Enter name: ";
                cin >> list[numFriends].name;
                cout << "Enter phone: ";
                cin >> list[numFriends].phone;
                cout << "Enter email: ";
                cin >> list[numFriends].email;
                numFriends++;
            }
            // Edit.
            else if (input == "E") {
                // Get index to change.
                cout << "Enter Num of friend to edit (0-" << numFriends - 1 << "):";
                cin >> editNum;
                while ((editNum >= numFriends) || (editNum < 0)) {
                    cout << "Invalid entry! Try again!" << endl;
                    cout << "Enter Num of friend to edit (0-" << numFriends - 1 << "): ";
                    cin >> editNum;
                }
                // Get name, phone, email.
                cout << "Enter new name: ";
                cin >> list[editNum].name;
                cout << "Enter new phone: ";
                cin >> list[editNum].phone;
                cout << "Enter new email: ";
                cin >> list[editNum].email;
            }
            // Exit
            else if (input == "X") {
                cout << "Thanks for using Friender!" << endl;
            }
            // Friend list full.
            else {
                cout << "Sorry, friend list is full.\n" << endl;
            }
        }
        else {
            cout << "Invalid entry! Try again!\n";
            cout << "Enter A, E or X: "; cin >> input;
            input = toupper(input[0]);
        }
    }

    fin.close();

    system("pause");
    return 0;
}
