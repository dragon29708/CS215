//-------------------------------------------------------------------
//                      catalog Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "catalog.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
catalog::catalog() {
    // set strings to "" and numbers to 0
    numCoursesInCatalog = 0;
}// catalog()



//-------------------------------------------------------------------
//                               getNumCourses
//-------------------------------------------------------------------
int catalog::getNumCourses() {
    return numCoursesInCatalog;
}// getNumCourses()


//-------------------------------------------------------------------
//                               getCourse
//-------------------------------------------------------------------
course catalog::getCourse(int index) {
	// return empty course object if index out of catalog list range
	if (index < 0 || index >= numCoursesInCatalog) {
		course emptyCourse;
		return emptyCourse;
	}
	else
		return courseCatalog[index]; // range good. return course obj
}// getCourse()



//-------------------------------------------------------------------
//                               search
//-------------------------------------------------------------------
int catalog::search(string idSearch) {
    // find index where course is
    int indexFound = -1;
    for (int i = 0; i < numCoursesInCatalog; i++) {
		if (idSearch == courseCatalog[i].getCourseId()) {
			indexFound = i;
			return indexFound; // index found. return it as an int
		}
    }

    // will return index or -1 if no course found
    return indexFound;
}// search()


//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
void catalog::print() {
	// print the catalog in a fancy way
    cout << "=============== COURSE CATALOG ================\n";
    cout << "ID    DEPT NUMB HRS TITLE\n";
    cout << "----- ---- ---- --- ------------------------------\n";
    // print out all courses
    for (int i = 0; i < numCoursesInCatalog; i++) {
        courseCatalog[i].print();
    }
    
    cout << "=========== # courses listed: " << numCoursesInCatalog << " =============\n";

    cout << endl;
    system("pause");
    cout << endl;
}// print()


//-------------------------------------------------------------------
//                               read
//-------------------------------------------------------------------
void catalog::read() {
    ifstream fin;
    fin.open("catalog.txt");
    
    string id, num, dep, title;
    int hours;

    // for each line in catalog.txt get the variables from the read 
    // file and use the catalog sets/gets to throw them in course 
    // objects in our catalog list
    for (int i = 0; i < 50; i++) {
    	fin >> id >> dep >> num >> hours; getline(fin, title);
    	if (id != "XXXXX") {
    		courseCatalog[i].setCourseId(id);
    		courseCatalog[i].setDepartment(dep);
    		courseCatalog[i].setCourseNum(num);
    		courseCatalog[i].setCreditHours(hours);
    		courseCatalog[i].setCourseTitle(title);
    		numCoursesInCatalog++;
    	}
    	else
    		i = 50; // used a for loop so no fear of infinite loop.
    				// breaks the loop by setting i = 50 when no more courses left in file

    }
    fin.close();
}// read()
