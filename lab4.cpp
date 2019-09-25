/*
--------------------------------------------------------------------
                        CS215-401 Lab 4
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 9/17/2019
Description: A program that calculates student grades by reading and
writing to files.
--------------------------------------------------------------------
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    // Intialize variables.
    string readFile;
    bool fileBool;

    // Build my read file object for reading a file.
    ifstream fin;

    // Get input and file from user.
    cout << "Enter input file name: "; cin >> readFile;

    // If readFile will not open.
    while (fileBool != true) {
        if (fin.fail(readFile)) {
            // File cannot be opened. Program exits.
            cout << "Unable to open file " << readFile;
            system("Pause");
            return 0;
        }
        else
            fileBool = true;
    }

    // Get output file from user.

    // If file opens, read contents of selected files into variables.


        // Compute averages and any info neccesary for report.


        // Generate and write report to user specified text file.


        // Output to user where report text has been saved to.


    // Else ouput to user that file cannot be opened.


    // End statements.
    system("Pause");
    return 0;
}
