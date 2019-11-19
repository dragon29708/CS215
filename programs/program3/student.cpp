//-------------------------------------------------------------------
//                      student Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
student::student() {
    // set strings to "" and numbers to 0
	studentId = "";
	string firstName = lastName = "";
	totalCreditHours = 0;
}// student()



//-------------------------------------------------------------------
//                                 setId
//-------------------------------------------------------------------
void student::setId(string newId) {
     studentId = newId;
}// setId()


//-------------------------------------------------------------------
//                                 setFirstName
//-------------------------------------------------------------------
void student::setFirstName(string newFirstName) {
    firstName = newFirstName;
}// setFirstName()


//-------------------------------------------------------------------
//                                 setLastName
//-------------------------------------------------------------------
void student::setLastName(string newLastName) {
    lastName = newLastName;
}// setLastName()


//-------------------------------------------------------------------
//                                 setTotalCreditHours
//-------------------------------------------------------------------
void student::setTotalCreditHours(int creditHours) {
    totalCreditHours = creditHours;
}// setTotalCreditHours()


//-------------------------------------------------------------------
//                                 getId
//-------------------------------------------------------------------
string student::getId() {
    return studentId;
}// getId()


//-------------------------------------------------------------------
//                                 getFirstName
//-------------------------------------------------------------------
string student::getFirstName() {
    return firstName;
}// getFirstName()


//-------------------------------------------------------------------
//                                 getLastName
//-------------------------------------------------------------------
string student::getLastName() {
    return lastName;
}// getLastName()

//-------------------------------------------------------------------
//                                 getTotalCreditHours
//-------------------------------------------------------------------
int student::getTotalCreditHours() {
    return totalCreditHours;
}// getTotalCreditHours()


//-------------------------------------------------------------------
//                                 print
//-------------------------------------------------------------------
// prints private data members
void student::print() {
    cout << setw(5)  << left  << studentId               << " ";
    cout << setw(3)  << right << totalCreditHours << " ";
    cout << setw(15) << left  << lastName         << " ";
    cout << setw(15) << left  << firstName        << endl;
}// print()
