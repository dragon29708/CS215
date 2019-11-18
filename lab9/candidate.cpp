#include <iostream>
#include <iomanip>
#include "candidate.h"

//------------------------------------------------------------------
//                        short methods
//------------------------------------------------------------------
candidate::candidate() { name = party = ""; ballotNum = votes = 0; }
void candidate::setBallotNum(int newBallotNum) { ballotNum = newBallotNum; }
void candidate::setVotes(int newVotes) { votes = newVotes; }
void candidate::setName(string newName) { name = newName; }
void candidate::setParty(string newParty) { party = newParty; }
int  candidate::getBallotNum() { return ballotNum; }
int  candidate::getVotes() { return votes; }
string candidate::getName() { return name; }
string candidate::getParty() { return party; }
void candidate::addVote() { votes++; }

//---------------------------------------------------
//                     print
//---------------------------------------------------
// prints the data on the ballot for this candidate
void candidate::print() {
	cout << setw(2) << ballotNum << "  " << party << "  " << name << endl;
} // print()