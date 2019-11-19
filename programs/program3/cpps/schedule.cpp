//-------------------------------------------------------------------
//                      schedule Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include "schedule.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
schedule::schedule() {
    // set strings to "" and numbers to 0
    studentId = "";
    for (int i = 0; i < MAX_COURSES; i++)
        courses[i] = "";
    numCourses = 0;
}// schedule()


//-------------------------------------------------------------------
//                               setStudentId
//-------------------------------------------------------------------
void schedule::setStudentId(string newStudentId) {
    studentId = newStudentId;
}// setStudentId()


//-------------------------------------------------------------------
//                               getStudentId
//-------------------------------------------------------------------
string schedule::getStudentId() {
    return studentId;
}// getStudentId()


//-------------------------------------------------------------------
//                               getCourseId
//-------------------------------------------------------------------
string schedule::getCourseId(int index) {
	// return empty string when index out of course list range
    if (index < 0 || index >= numCourses)
        return "";
    else
        return courses[index]; // range good. return courseId
}// getCourseId()


//-------------------------------------------------------------------
//                               getNumCourses
//-------------------------------------------------------------------
int schedule::getNumCourses() {
    return numCourses;
}// getNumCourses()



//-------------------------------------------------------------------
//                               addCourse
//-------------------------------------------------------------------
int schedule::addCourse(string inId) {
    // append id to courseId list if list not full, else return -1
    if (numCourses < MAX_COURSES) {
        courses[numCourses] = inId;
        numCourses++;
        return 0;
    }
    else
        return -1;
}// addCourse()


//-------------------------------------------------------------------
//                               dropCourse
//-------------------------------------------------------------------
int schedule::dropCourse(string outId) {
    // find index where course wanted to drop is
    int indexFound = -1;
    for (int i = 0; i < numCourses; i++) {
        if (outId == courses[i])
            indexFound = i;
    }

    // if course was found, delete and re-organize list
    if (indexFound != -1) {
        // shift list
        for (int i = indexFound; i < numCourses; i++)
            courses[i] = courses[i+1];

        // return 0 after removing courseId from list
        return 0;
    }
    else
        // if course not found in list, return -1
        return indexFound;
}// dropCourse()


//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// print out private data members
void schedule::print() {
    cout << setw(5) << left  << studentId  << " ";
    cout << setw(2) << right << numCourses << " ";
    for (int i = 0; i < numCourses; i++)
        cout << courses[i] << " ";
    cout << endl;
}// print()
