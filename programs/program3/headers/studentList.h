//-------------------------------------------------------------------
//                      studentList Class Decleration
//-------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

const int MAX_NUM_STUDENTS = 50;

class studentList {
public:
    // constructor
    studentList();
    // print
    void print();
    // search
    student search(string checkId);
    // search
    student search(int index);
    // read
    void read();
private:
    student studList[MAX_NUM_STUDENTS];
    int numStudentsInList;
};
