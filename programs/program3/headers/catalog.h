//-------------------------------------------------------------------
//                      catalog Class Decleration
//-------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "course.h"

using namespace std;

const int MAX_CATALOG = 50;
const int CRS_NOT_FOUND = -1;

class catalog {
public:
    // constructor
    catalog();
    // gets
    int getNumCourses();
    course getCourse(int index);
    // searches for a course id
    int search(string idSearch);
    // prints course catalog
    void print();
    // reads info from catalog.txt
    void read();
private:
    course courseCatalog[MAX_CATALOG];
    int numCoursesInCatalog;
};
