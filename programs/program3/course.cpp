//-------------------------------------------------------------------
//                      course Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include "course.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
course::course() {
    // set strings to "" and numbers to 0
    courseId = "";
    courseNum = "";
    creditHours = 0;
    department = "";
    courseTitle = "";
}// course()



//-------------------------------------------------------------------
//                               setCourseId
//-------------------------------------------------------------------
void course::setCourseId(string newId) {
    courseId = newId;
}// setCourseId()


//-------------------------------------------------------------------
//                               setCourseNum
//-------------------------------------------------------------------
void course::setCourseNum(string newCourseNum) {
    courseNum = newCourseNum;
}// setCourseNum()


//-------------------------------------------------------------------
//                               setCreditHours
//-------------------------------------------------------------------
void course::setCreditHours(int newHours) {
	// default num hours to zero if input is < 0
	if (newHours < 0)
		creditHours = 0;
    else
        creditHours = newHours; // use input value
}// setCreditHours()


//-------------------------------------------------------------------
//                               setDepartment
//-------------------------------------------------------------------
void course::setDepartment(string newDep) {
    department = newDep;
}// setDepartment()


//-------------------------------------------------------------------
//                               setCourseTitle
//-------------------------------------------------------------------
void course::setCourseTitle(string newTitle) {
    courseTitle = newTitle;
}// setCourseTitle()


//-------------------------------------------------------------------
//                               getCourseId
//-------------------------------------------------------------------
string course::getCourseId() {
    return courseId;
}// getCourseId()


//-------------------------------------------------------------------
//                               getCourseNum
//-------------------------------------------------------------------
string course::getCourseNum() {
    return courseNum;
}// getCourseNum()


//-------------------------------------------------------------------
//                               getCreditHours
//-------------------------------------------------------------------
int course::getCreditHours() {
    return creditHours;
}

//-------------------------------------------------------------------
//                               getDepartment
//-------------------------------------------------------------------
string course::getDepartment() {
    return department;
}// getDepartment()


//-------------------------------------------------------------------
//                               getCourseTitle
//-------------------------------------------------------------------
string course::getCourseTitle() {
    return courseTitle;
}// getCourseTitle()



//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// prints private data members
void course::print() {
    cout << setw(5)  << left  << courseId    << " ";
    cout << setw(4)  << left  << department  << " ";
    cout << setw(4)  << left  << courseNum   << " ";
    cout << setw(3)  << right << creditHours << " ";
    cout << setw(20) << left  << courseTitle << endl;
}// print()
