//-------------------------------------------------------------------
//                      schedList Class Definition
//-------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "schedList.h"

using namespace std;


//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
schedList::schedList() {
    // set strings to "" and numbers to 0
	numSchedulesInLst = 0;
}//schedList()



//-------------------------------------------------------------------
//                               getSchedule
//-------------------------------------------------------------------
schedule schedList::getSchedule(int index) {
	// return empty schedule obj when index out of range
	if (index < 0 || index >= numSchedulesInLst) {
		schedule emptySchedule;
		return emptySchedule;
	}
	else
		return schedLst[index]; // range good. return schedule obj at index
}// getSchedule()


//-------------------------------------------------------------------
//                               getSchedule
//-------------------------------------------------------------------
schedule schedList::getSchedule(string checkId) {
	for (int i = 0; i < numSchedulesInLst; i++) {
		if (schedLst[i].getStudentId() == checkId)
			return schedLst[i];  // return the schedule if found
	}

	schedule emptySchedule;
	return emptySchedule;        // return empty schedule obj if not found
}// getSchedule()



//-------------------------------------------------------------------
//                               addSchedule
//-------------------------------------------------------------------
void schedList::addSchedule(schedule newSched) {
	string studId = newSched.getStudentId();

	// if the student is already in the schedList, put their new
	// schedule where their old schedule was
	for (int i = 0; i < numSchedulesInLst; i++) {
		if (schedLst[i].getStudentId() == studId) {
			schedLst[i] = newSched;
			return;
		}
	}

	// new schedule was not found in list. if list not full, add it.
	if (numSchedulesInLst != MAX_SCHED) {
		schedLst[numSchedulesInLst] = newSched;
		numSchedulesInLst++;
	}
	// list was full
	else
		cout << "Error: Schedule list is full. Cannot add new schedule.\n";
}// addSchedule()


//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
void schedList::print() {
	// print the schedule list in a fancy way
	cout << "=============== ALL SCHEDULES (" << numSchedulesInLst << ") =================\n";
    cout << "STUID #C COURSE IDS\n";
    cout << "----- -- ---------------------------------------------\n";

	for (int i = 0; i < numSchedulesInLst; i++)
		schedLst[i].print();

	cout << endl;
    system("pause");
    cout << endl;
}// print()


//-------------------------------------------------------------------
//                               read
//-------------------------------------------------------------------
void schedList::read() {
	ifstream fin;
	fin.open("schedList.txt");

	fin >> numSchedulesInLst;  // number of schedules in schedule.txt

    string newStudId;
    int numCourses;

    // add schedules to the schedule array
	for (int i = 0; i < numSchedulesInLst; i++) {
        schedule newSched;
        schedLst[i] = newSched;

        fin >> newStudId >> numCourses;
        schedLst[i].setStudentId(newStudId);

        string course;
        for (int j = 0; j < numCourses; j++) {
            fin >> course;
            schedLst[i].addCourse(course);
        }
	}

	fin.close();
}// read()


//-------------------------------------------------------------------
//                               write
//-------------------------------------------------------------------
void schedList::write() {
    ofstream fout;
    fout.open("schedList_1.txt");

    fout << numSchedulesInLst << endl;

    // output each schedules info
    for (int i = 0; i < numSchedulesInLst; i++) {
        int num = schedLst[i].getNumCourses();

        fout << schedLst[i].getStudentId() << " " << num << " ";
        // output each schedules courses
        for (int j = 0; j < num; j++) {
            fout << schedLst[i].getCourseId(j) << " ";
        }

        fout << endl;
    }

    fout.close();
}// write()
