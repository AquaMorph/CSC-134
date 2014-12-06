// Rectangle.h
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Rectangle
{
public:

	Rectangle(); // default constructor
	Rectangle(double x); // constructor l and w are equal
	Rectangle(double x, double y); // constructor with two parameters
	Rectangle(Rectangle& rx); // copy constructor
	
	double getLength(); // getters
	double getWidth();
	
	
	void setLength(double x); // setters
	void setWidth(double x);
	
	double area(); // returns the area
	double perimeter(); // returns the perimeter
	double diagonal(); // returns the diagonal of the rectangle
	double largestSide(); // returns the larger of w and l
	
	double smallestSide(); // returns the smaller of w and l
	string describe(); // returns a string with the rectangle properties
	
	bool isSquare(); // returns true if the Rectangle is a square i.e. l == w
	
	string typeRectangle(); // returns "square" if the Rectangle is a square
	// other wise returns "rectangle"
	// make sure you call isSquare function
	bool isEmpty(); // returns true if the area of the rectangle
	// is zero otherwise returns false
	
	bool operator==(const Rectangle other); // are two Rectangles equal ?
	// const == do not change anything


private:
	double l; // length
	double w; // width
}; // end class Rectangle 
