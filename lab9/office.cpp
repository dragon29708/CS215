#include<iostream>
#include<string>
#include<iomanip>
#include "office.h"
#include "candidate.h"
using namespace std;

//------------------------------------------------------------------------------
//                               Constructor
//------------------------------------------------------------------------------
office::office() {
	name = "";
	numCand = 0;
}// office()


//------------------------------------------------------------------------------
//                               Sets and Gets
//------------------------------------------------------------------------------
void office::setOfficeName(string newName) {
	name = newName;
}// setOfficeName()

string office::getOfficeName() {
	return name;
}// getOfficeName()

int office::getNumCandidates() {
	return numCand;
}// getNumCandidates()

candidate office::getCandidate(int index) {
	if (index >= numCand || index < 0) {
		candidate emptyCand;
		return emptyCand; // return an empty candidate object if they enter in a bad index
	}
	else
		return lst[index];
}// getCandidate()


//-----------------------------------------------------------------------------
//                               Main Functions
//-----------------------------------------------------------------------------
void office::addCandidate(int ballotNum, string party, string newCandName) {
	if (numCand < MAX_CAND) {
		// set ballotNum, party and name of new candidate
		lst[numCand].setBallotNum(ballotNum);
		lst[numCand].setParty(party);
		lst[numCand].setName(newCandName);

		// increment num of candidates
		numCand++;
	}
	else
		cout << "office::addCandidate: max candidates exceeded\n";
}// addCandidate()

void office::doVote() {
	// print office ballet
	print();

	// get ballot num
	int ballotNum;
	cout << "Enter ballot bumber: "; cin >> ballotNum;

	while (ballotNum > numCand || ballotNum < 1 ) {
		cout << "Invalid input. Enter ballot number: "; cin >> ballotNum;
	}

	ballotNum--;                  // index to use is one less than ballotNum

	lst[ballotNum].addVote();     // give vote to given candidate

	cout << "You voted for " << lst[ballotNum].getName() << ". Thank you!\n";

}// doVote()

void office::print() {
	// election for "OFFICE NAME"
	cout << "Election for " << name << endl;

	// print out each candidate
	for (int i = 0; i < numCand; i++) {
		lst[i].print();
	}

}// print()

void office::printReport() {
	cout << "Report of Election for " << name << endl;

	for (int i = 0; i < numCand; i++) {
		cout << setw(2)  <<  right <<  i+1 <<                "  ";
		cout << setw(3)  <<  left  <<  lst[i].getParty() <<  "  ";
		cout << setw(15) <<  left  <<  lst[i].getName()  <<  "  ";
		cout << setw(4)  <<  right <<  lst[i].getVotes() <<  endl;
	}
}// printReport()
