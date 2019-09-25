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
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main() {
    // Read and write files.
    string readFile, writeFile;
    // Amount of students, class days, exams and projects.
    int numStudents, numClassDays;
    const float numExams = 2.0, numProjs = 3.0;
    // Student names.
    string firstName, lastName;
    // Grade report variables.
    int exam1, exam2, proj1, proj2, proj3, absentCount;
    // Average scores per student for grade report.
    float examAvg, projAvg, attdAvg, ovrlAvg;
    // Assignment weights for overall grade calculation.
    const float examWeight = 0.50, projWeight = 0.30, attdWeigt = 0.20;

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

    // Generate and write report to user specified text file.
    ofstream fout;
    fout.open(writeFile);
    fout << "----------------------------------------------\n";
    fout << "              Class Grade Report              \n";
    fout << "----------------------------------------------\n";
    fout << "       Student       Exam  Proj  Attn  Overall\n";
    fout << "-------------------- ----- ----- ----- -----  \n";

    // Get number of students and number of class days.
    fin >> numStudents >> numClassDays;

    // Ouput a report line per student.
    for (int i = 0; i < numStudents; i++) {

        // Loop over the readFile and get first, last, scores, etc.
        fin >> firstName >> lastName >> exam1 >> exam2;
        fin >> proj1 >> proj2 >> proj3 >> absentCount;

        // Compute averages and any info neccesary for report.
        examAvg = ((exam1 + exam2) / numExams) * 100;
        projAvg = ((proj1 + proj2 + proj3) / numProjs) * 100;
        attdAvg = ((numClassDays - absentCount) / static_cast<float>(numClassDays)) * 100;
        ovrlAvg = (examAvg * examWeight + projAvg * projWeight + attdAvg * attdWeigt) * 100;

        // Write report per student.
        fout << setw(20) << lastName << ", " << firstName;
        fout << setw(5) << examAvg << projAvg << attdAvg << ovrlAvg << "\n";
    }

    // Last line for looks.
    fout << "----------------------------------------------";

    // Close readFile and writeFile.
    fin.close();
    fout.close();

    // Output to user where report text has been saved to.
    cout << "Grade report written to: " << writeFile;

    // End statements.
    system("Pause");
    return 0;
}
