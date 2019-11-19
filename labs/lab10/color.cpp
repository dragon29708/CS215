// color class definition
// author: Andrew Cassidy

#include <iostream>
#include <string>
#include "color.h"

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
color::color() {
	// all color to zero
	red = 0;
	green = 0;
	blue = 0;
}// constructor


//-------------------------------------------------------------------
//                               setColors
//-------------------------------------------------------------------
void color::setColors(int newRed, int newGreen, int newBlue) {
	// red = 0 when < 0. red = 255 when > than 255. else set red
	// to newRed value
	if (newRed < 0)
		red = 0;
	else if (newRed > 255)
		red = 255;
	else
		red = newRed;

	// green = 0 when < 0. green = 255 when > than 255. else set green
	// to newGreen value
	if (newGreen < 0)
		green = 0;
	else if (newGreen > 255)
		green = 255;
	else
		green = newGreen;

	// blue = 0 when < 0. blue = 255 when > than 255. else set blue
	// to newGreen value
	if (newBlue < 0)
		blue = 0;
	else if (newBlue > 255)
		blue = 255;
	else
		blue = newBlue;
}// setColors()


//-------------------------------------------------------------------
//                               getRed
//-------------------------------------------------------------------
int color::getRed() {
	return red;
}// getRed()


//-------------------------------------------------------------------
//                               getGreen
//-------------------------------------------------------------------
int color::getGreen() {
	return green;
}// getGreen()


//-------------------------------------------------------------------
//                               getBlue
//-------------------------------------------------------------------
int color::getBlue() {
	return blue;
}// getBlue()


//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
void color::print() {
	// print color vars in pretty format
	cout << "R:" << red << " G:" << green << " B:" << blue << endl;
}// print()


//-------------------------------------------------------------------
//                               color operator +
//-------------------------------------------------------------------
color operator + (color c1, color c2) {
	// color obj to throw c1+c2 values into
	color newColor;
	int newRed, newGreen, newBlue;

	// add up c1 and c2's colors
	newRed = c1.red + c2.red;
	newGreen = c1.green + c2.green;
	newBlue = c1.blue + c2.blue;

	// set the colors into newColor obj.
	// the set method will fix any out of
	// range color values.
	newColor.setColors(newRed, newGreen, newBlue);

	return newColor;
}// color operator +


//-------------------------------------------------------------------
//                               color operator -
//-------------------------------------------------------------------
color operator - (color c1, color c2) {
	// color obj to throw c1-c2 values into
	color newColor;
	int newRed, newGreen, newBlue;

	// subtract c1 and c2's colors
	newRed = c1.red - c2.red;
	newGreen = c1.green - c2.green;
	newBlue = c1.blue - c2.blue;

	// set the colors into newColor obj.
	// the set method will fix any out of
	// range color values.
	newColor.setColors(newRed, newGreen, newBlue);

	return newColor;
}// color operator -


//-------------------------------------------------------------------
//                               color operator *
//-------------------------------------------------------------------
color operator * (int num, color c1) {
	// color obj to throw num*c2 values into
	color newColor;
	int newRed, newGreen, newBlue;

	// multiple num to c1's color values
	newRed = num * c1.getRed();
	newGreen = num * c1.getGreen();
	newBlue = num * c1.getBlue();

	// set the colors into newColor obj.
	// the set method will fix any out of
	// range color values.
	newColor.setColors(newRed, newGreen, newBlue);

	return newColor;
}// color operator *


//-------------------------------------------------------------------
//                               color operator /
//-------------------------------------------------------------------
color operator / (color c1, int num) {
	// color obj to throw num*c2 values into
	color newColor;
	int newRed, newGreen, newBlue;

	if (num != 0) {
		// divide c1's color values by num
		newRed = c1.getRed() / num;
		newGreen = c1.getGreen() / num;
		newBlue = c1.getBlue() / num;
	}
	else
		newRed = newGreen = newBlue = 0;

	// set the colors into newColor obj.
	// the set method will fix any out of
	// range color values.
	newColor.setColors(newRed, newGreen, newBlue);

	return newColor;	
}// color operator /