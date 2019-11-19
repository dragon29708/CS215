#pragma once
//----------------------------------------------------------------------
//                         userint class
//----------------------------------------------------------------------
// This class implements the user interface for the Student Course
// Registration project.
//----------------------------------------------------------------------
// INSTRUCTIONS: you may have to change the names of .h files, classes,
// and/or methods of classes to match those you have written;
// OR
// change the names in your code to match those used here
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
#include "schedList.h"
#include "studentList.h"
#include "catalog.h"
#include "menu.h"

class userint {
public:
	userint();
	void go();
private:
	schedList   scList;
	catalog     cat;
	studentList stuList;
	menu        mainMenu;
	menu        regMenu;
	void registerStudent();
	void printSchedule(student stu, schedule sched);
	void addCourse(student stu, schedule& sched);
	void dropCourse(student stu, schedule& sched);
};
