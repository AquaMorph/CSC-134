// RectangleMain.cpp
#include <iostream>
#include "Rectangle.cpp"
void displayRectangleArray (Rectangle rax[], int nx) ; // done
 // calls the describe() function for each of the rectangles in the array rax
void fillRectangleArray (Rectangle rax[], int nx) ;
// calls the two parameter constructor for each of the rectangles in the array rax
int nSquares(Rectangle rax[], int nx) ;
// returns the number of squares in the Rectangle array
int equalRectangles(Rectangle rax[], int nx) ;
// returns the number of rectangles in the Rectangle array that are equal to rax[0]
using namespace std; ;
// function main begins program execution
int main()
{
	Rectangle r1; // default constructor l and w == 1
	cout << "enter side for Rectangle r2..." ;
	double s ;
	cin >> s ;
	Rectangle r2(s) ; // one parameter constructor l == s amd w == s
	Rectangle r3(2.1, 13) ; // two parameter constructor
	// l == 2 w == 3
	Rectangle r4(r3) ; // r4 is a copy of r3
	// copy constructor called
	
	
	// display each Rectangles values
	cout << "Rectangle r1 is: " << r1.describe() << endl ;
	cout << "Rectangle r2 is: " << r2.describe() << endl ;
	cout << "Rectangle r3 is: " << r3.describe() << endl ;
	cout << "Rectangle r4 is: " << r4.describe() << endl ;

	// operator== called in TWO different ways
	if (r1 == r2) { cout << "Rectangles r1 and r2 are equal " ; }
	// same as calling t1.operator==(t2)
	else { cout << "Rectangles r1 and r2 are NOT equal " ; }
	cout << endl ;
	
	// for r3 and r4
	if (r3.operator==(r4) ){ cout << "Rectangles r3 r4 are equal " ; }
	// same as calling r3 == r4
	else { cout << "Rectangles r3 r4 are NOT equal " ; }
	
	// overloading an operator can be thought of redefining a function
	cout << endl << endl ; 
	// ARRAY of 100 RECTANGLES
	int n = 100;
	Rectangle ra[n]; // do NOT change
	// fill, by using a random number function1, the array of Rectangles ta[n]
	// (see above) with
	// (1) random doubles in the range 10.0 – 20.0 (call your random function)
	// use the void fillRectangleArray (Rectangle rax[], int nx) ;
	// fill the array
	cout << endl << "fill the array with instances of Rectangles..." << endl ;
	fillRectangleArray ( ra, n) ;
	// (2) call the displayRectangleArray (Rectangle rax[], int nx)
	// function to display each member of ra
	cout << endl << "Display Rectangles in the array..." << endl ;
	displayRectangleArray ( ra, n) ;
	
	// number of squares and rectangles (non squares) FUNCTION needs work
	int nsq = nSquares(ra, n) ;
	cout << endl << "The number of squares in the array..." << nsq << endl ;
	 cout << " number of rectangles is ..." << n - nsq << endl ;
	// (3) determine if any of the Rectangles in the array are equal
	// to ra[0] the first rectangle in the array
	// (call the operator==( ) function)in the function
	int e = equalRectangles(ra, n) ;
	cout << "the number of rectangle in the array equal to ra[0] is " << e ;
	// TO DO ===================
	// (4) determine the rectangle with max area in the array
	// call the describe function for the rectangle in the array with largest area
	// assuming the rectangle with the largest area is ra[50] NOT CORRECT
	// your output should be
	cout << endl << "the rectangle with largest area is " << ra[50].describe() ;
	// TO CHECK your WORK let n = 125 above
	// system("pause") ; // may be required to pause on your system
	return 0 ;
}

void displayRectangleArray (Rectangle rax[], int nx)
{
	for (int j = 0 ; j < nx; j++)
	{
		cout << rax[j].describe() << endl;
	}
}
// this fill array function is not correct
// use your random generator function to call the setters
void fillRectangleArray (Rectangle rax[], int nx)
{
	for (int k = 0; k < nx; k++)
	{
		rax[k].setWidth(k+1); // random should be here
		rax[k].setLength(k+2); // random should be here
	}
}
// this nSquares function is not correct
// use your isSquare() function to determine the number of squares
// in the array
int nSquares(Rectangle rax[], int nx)
{
	int n = -1;
	return n;
}
// determine if any of the Rectangles in the array are equal
// to ra[0] the first rectangle in the array
// this function is not correct
// call the operator==() function
int equalRectangles(Rectangle rax[], int nx)
{
	int n = -1;
	return n;
}
