//--------------------------------------------------------
//                CS 215 - Fall 2019 - Lab 8
//--------------------------------------------------------
// Author: Andrew Cassidy
// Section: 401
// This program tests the student class for lab 8.
//--------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;
#include"student.h"
#include"student.cpp"

int main() {
	student s;		// create one student object

	// test empty student 
	cout << "Empty student: \n";
	s.print();
	cout << "Avg=" << s.getAvg() << endl;

	cout << "\nTesting setName and addScore...\n";
	s.setName("George");
	s.addScore(88);
	s.addScore(77);
	s.addScore(99);
	s.addScore(85);
	s.addScore(75);
	s.addScore(95);
	s.addScore(81);
	s.addScore(91);
	s.addScore(71);
	s.addScore(100);
	s.addScore(50);		// should fail; array is full
	cout << "\nAll scores added: \n";
	s.print();

	cout << "\nTesting gets:\n";
	cout << "Name = " << s.getName() << endl;
	cout << "Avg  = " << s.getAvg() << endl;
	cout << "#Scores = " << s.GetNumScores() << endl << endl;

	cout << "Test another student object:\n";
	student t;		// create another object NOW
	t.setName("Mary");
	t.addScore(88);
	t.addScore(99);
	t.addScore(77);
	t.print();
	cout << endl;

	system("pause");
	return 0;
}