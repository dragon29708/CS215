#pragma once
//---------------------------------------------------------------------
//                           class candidate
//---------------------------------------------------------------------
// Describes a candidate for an office on an election ballot
#include <string>
using namespace std;

class candidate {
public:
	candidate();
	void setBallotNum(int newBallotNum);
	void setVotes(int newVotes);
	void setName(string newName);
	void setParty(string newParty);
	int  getBallotNum();
	int  getVotes();
	string getName();
	string getParty();
	void   addVote();
	void   print();
private:
	int ballotNum;   // the number for voting for this candidate...1,2,3,etc.
	int votes;       // the number of votes for this candidate
	string name;     // full name
	string party;    // usually a 3-char code, DEM, REP, LIB, OTR, etc.
};