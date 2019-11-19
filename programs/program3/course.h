//-------------------------------------------------------------------
//                      course Class Declaration
//-------------------------------------------------------------------
#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class course {
public:
    // constructor
    course();
    // sets
    void setCourseId(string newId);
    void setCourseNum(string newCourseNum);
    void setCreditHours(int newHours);
    void setDepartment(string newDep);
    void setCourseTitle(string newTitle);
    // gets
    string getCourseId();
    string getCourseNum();
    int getCreditHours();
    string getDepartment();
    string getCourseTitle();
    // prints private data members
    void print();
private:
    string courseId;
    string courseNum;
    int creditHours;
    string department;
    string courseTitle;
};
