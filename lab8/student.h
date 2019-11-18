#pragma once
#include<iostream>
#include<string>

using namespace std;

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