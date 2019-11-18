//-------------------------------------------------------------------
//                      studentList Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "studentList.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
studentList::studentList() {
    // set strings to "" and numbers to 0
    numStudentsInList = 0;
}// studentList()



//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
void studentList::print() {
	// print the student list in a fancy way
    cout << "================ STUDENT LIST (" << numStudentsInList << ") ====================\n";
    cout << "IDNUM HRS LAST            FIRST\n";
    cout << "----- --- --------------- ---------------\n";

    for (int i = 0; i < numStudentsInList; i++)
        studList[i].print();

    cout << endl;
    system("pause");
    cout << endl;
}// print()


//-------------------------------------------------------------------
//                               search
//-------------------------------------------------------------------
student studentList::search(string checkId) {
    // find student who has id = checkId
    for (int i = 0; i < numStudentsInList; i++) {
        if (checkId == studList[i].getId())
            return studList[i];
    }

    // id not found. return empty student object
    student blankStudent;
    return blankStudent;
}// search()


//-------------------------------------------------------------------
//                               search
//-------------------------------------------------------------------
student studentList::search(int index) {
    // check for valid index
    if (index >= 0 && index < numStudentsInList) {
        return studList[index];
    }
    // invalid index. return empty student object
    else {
        student blankStudent;
        return blankStudent;
    }
}// search()


//-------------------------------------------------------------------
//                               read
//-------------------------------------------------------------------
void studentList::read() {
    ifstream fin;
    fin.open("stulist.txt");

    fin >> numStudentsInList;

    string studId, first, last;
    int hours;
    for (int i = 0; i < numStudentsInList; i++) {
        // make new student to fill with data per line in stulist.txt
        student newStud;

        fin >> studId >> first >> last >> hours;

        // put per line info into student object
        newStud.setId(studId);
        newStud.setFirstName(first);
        newStud.setLastName(last);
        newStud.setTotalCreditHours(hours);

        // throw student object into list
        studList[i] = newStud;
    }

    fin.close();
}// read()