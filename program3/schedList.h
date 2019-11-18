//-------------------------------------------------------------------
//                      schedList Class Decleration
//-------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include "schedule.h"

using namespace std;

const int MAX_SCHED = 10;

class schedList {
public:
	// constructor
	schedList();
	// gets
	schedule getSchedule(int index);
	schedule getSchedule(string checkId);
	// add a schedule
	void addSchedule(schedule newSched);
	// print
	void print();
	// read
	void read();
	// write
	void write();
private:
	schedule schedLst[MAX_SCHED];
	int numSchedulesInLst;
};
