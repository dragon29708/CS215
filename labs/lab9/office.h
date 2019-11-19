#pragma once

#include<string>
#include "candidate.h"
using namespace std;

// max number of candidates
const int MAX_CAND = 5;

class office {
public:
	office();
	void setOfficeName(string newName);
	string getOfficeName();
	int getNumCandidates();
	void addCandidate(int ballotNum, string party, string newCandName);
	candidate getCandidate(int index);
	void doVote();
	void print();
	void printReport();
private:
	string name;                // office name
	candidate lst[MAX_CAND];    // partial arrays of candidates in office
	int numCand;				// number of candidates in partial array
};