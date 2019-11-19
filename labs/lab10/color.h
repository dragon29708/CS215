// color class declaration
// author: Andrew Cassidy

#include <iostream>
#include <string>

using namespace std;

class color {
public:
	// constructor
	color();
	// set all values
	void setColors(int newRed, int newGreen, int newBlue);
	// gets
	int getRed();
	int getGreen();
	int getBlue();
	//print
	void print();
	//overloaded operators
	friend color operator + (color c1, color c2);
	friend color operator - (color c1, color c2);
private:
	unsigned int red, green, blue;
};

color operator * (int int1, color c1);
color operator / (color c1, int int1);