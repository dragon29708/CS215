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



    fin.close();

    system("pause");
    return 0;
}
