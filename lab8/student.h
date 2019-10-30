//--------------------------------------------------------
//                CS 215 - Fall 2019 - Lab 8
//--------------------------------------------------------
// Author: Andrew Cassidy
// Section: 401
// student class definition used in lab 8
//--------------------------------------------------------


#include<string>

const int MAX_SCORES = 10;

class student {
public:
	student();
	void setName(string newName);
	string getName();
	int GetNumScores();
	void addScore(int newScore);
	float getAvg();
	void print();
private:
	string name;
	int scores[MAX_SCORES];
	int numScores;
};