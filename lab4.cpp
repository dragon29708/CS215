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
    string readFile, writeFile;
    bool fileBool = false;

    // Build my read file object for reading a file.
    ifstream fin;

    // Get input and file from user.
    cout << "Enter input file name: "; cin >> readFile;

    // Open the file for reading.
    fin.open(readFile);

    // If the file doesn't exist, unable to open or in wrong repo, then exit program.
    if (fin.fail()) {
        // File cannot be opened. Program exits.
        cout << "Unable to open file " << readFile << endl;
        system("Pause");
        return 0;
    }

    // If the file can be opened and read from, get the output file from user for report.
    cout << "Enter output file name: "; cin >> writeFile;

    // Retrieve and store data from readFile.


    // Compute averages and any info neccesary for report.


    // Generate and write report to user specified text file.


    // Output to user where report text has been saved to.
    cout << "Grade report written to: " << writeFile;

    // End statements.
    system("Pause");
    return 0;
}
