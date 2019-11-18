//-------------------------------------------------------------------
//                      student Class Declaration
//-------------------------------------------------------------------
#pragma once

#include<iostream>
#include<string>

using namespace std;

const int MAX_ID_LENGTH = 5;
const int MAX_FIRST_LENGTH = 15;
const int MAX_LAST_LENGTH = 15;

class student {
public:
	// constructor
	student();
	// sets
	void setId(string newId);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setTotalCreditHours(int creditHours);
	// gets
	string getId();
	string getFirstName();
	string getLastName();
	int getTotalCreditHours();
	// prints private data members
	void print();
private:
	string studentId;
	string firstName, lastName;
	int totalCreditHours;
};
