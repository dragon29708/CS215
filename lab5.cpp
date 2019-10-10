/*
--------------------------------------------------------------------
                         CS215-401 Lab 5
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/17/2019
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
    afriend list[MAX_FRIENDS];
    int numFriends;
    string friendFile;
    string input;

    // Build my read file object for reading a file.
    ifstream fin;

    cout << "Enter input file name: "; cin >> friendFile;

    fin.open(friendFile);

    // Exit app if file doesn't open.
    if (fin.fail()) {
        // File cannot be opened. Program exits.
        cout << "Unable to open file " << friendFile << endl;
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

    if ((input == "A") || (input == "E") || (input == "X"));
    else {
        cout << "Invalid entry! Try again!\n";
        cout << "Enter A, E or X: "; cin >> input;
        input = toupper(input[0]);
    }

    fin.close();

    system("pause");
    return 0;
}
