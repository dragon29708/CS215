//-------------------------------------------------------------------
//                      schedule Class Decleration
//-------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_COURSES = 10;

class schedule {
public:
    // constructor
    schedule();
    // sets
    void setStudentId(string newStudentId);
    // gets
    string getStudentId();
    string getCourseId(int index);
    int getNumCourses();
    // add and drop
    int addCourse(string inId);
    int dropCourse(string outId);
    // prints private data members
    void print();
private:
    string studentId;
    string courses[MAX_COURSES];
    int numCourses;
};
