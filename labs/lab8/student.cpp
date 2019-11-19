//--------------------------------------------------------
//                CS 215 - Fall 2019 - Lab 8
//--------------------------------------------------------
// Author: Andrew Cassidy
// Section: 401
// Function members for student class used in lab 8
//--------------------------------------------------------

#include"student.h"

student::student() {
	// initialize name to empty string
	name = "";

	// initialize all scores to zero
	for (int i = 0; i < MAX_SCORES; i++)
		scores[i] = 0;

	// initialize total scores to zero
	numScores = 0;

	// confirm constructor finished on object
	cout << "Constructed!\n";
}


void student::setName(string newName) {
	name = newName;
}


string student::getName() {
	return name;
}


int student::GetNumScores() {
	return numScores;
}


void student::addScore(int newScore) {
	if (numScores == MAX_SCORES)
		cout << "MAX SCORES exceeded!\n";
	else {
		scores[numScores] = newScore;
		numScores++;
	}
}


float student::getAvg() {
	if (numScores == 0)
		return 0.0;
	else {
		// add up the scores
		float total = 0;
		for (int i = 0; i < numScores; i++)
			total += scores[i];

		// calc and return avg of all scores
		float avg = total / numScores;
		return avg;
	}
}


void student::print() {
	cout << "Name=" << name << "   Avg=" << getAvg() << " #scores=" << numScores << "  ";
	for (int i = 0; i < numScores; i++)
		cout << scores[i] << " ";
	cout << endl;
}