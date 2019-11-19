#include <iostream>
#include <iomanip>
#include <string>
#include "office.h"

using namespace std;

int main() {
	candidate c;
	office o;

	cout << "Adding candidates...\n";
	o.setOfficeName("Super TA");
	o.addCandidate(1, "SLR", "Corey");
	o.addCandidate(2, "MON", "Shafika");
	o.addCandidate(3, "KAZ", "Anastasia");
	o.addCandidate(4, "TAS", "Tasmia");
	o.addCandidate(5, "SPR", "Clay");
	o.addCandidate(6, "XXX", "Joiner"); // this should fail, max 5 candidates

	cout << "\nPrinting report before voting begins...\n";
	o.printReport();
	system("pause");

	cout << "\nTesting gets...\n";
	cout << "Office name:    " << o.getOfficeName() << endl;
	cout << "Num candidates: " << o.getNumCandidates() << endl;
	for (int i = 0; i <= o.getNumCandidates(); i++) { // note: goes 1 too far
		c = o.getCandidate(i);                        // to test "invalid index"
		c.print();
	}
	system("pause");

	cout << "\nPolls are open! \n";
	for (int i = 0; i < 7; i++) // test for 7 voters
		o.doVote();

	cout << "\nPolls closed. Printing final report...\n";
	o.printReport();

	system("pause");
	return 0;
}