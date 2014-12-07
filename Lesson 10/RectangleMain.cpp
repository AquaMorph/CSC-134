///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: RectangleMain.cpp
// Date: December 11, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Hangles calculations with rectangles
//                                                                  
///////////////////////////////////////////////////////////////////////
#include "Rectangle.cpp"
void displayRectangleArray (Rectangle rax[], int nx);
void fillRectangleArray (Rectangle rax[], int nx);
int nSquares(Rectangle rax[], int nx);
int equalRectangles(Rectangle rax[], int nx);
double randomNum();
int largest(Rectangle rax[], int nx);

using namespace std; ;

int main()
{
	Rectangle r1;
	cout << "enter side for Rectangle r2...";
	double s;
	cin >> s;
	Rectangle r2(s);
	Rectangle r3(2.1, 13);
	Rectangle r4(r3);
	
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
	cout << endl << endl ; 
	
	// ARRAY of 100 RECTANGLES
	int n = 250;
	Rectangle ra[n];
	cout << endl << "fill the array with instances of Rectangles..." << endl ;
	fillRectangleArray ( ra, n) ;
	cout << endl << "Display Rectangles in the array..." << endl ;
	displayRectangleArray ( ra, n) ;
	int nsq = nSquares(ra, n) ;
	cout << endl << "The number of squares in the array..." << nsq << endl ;
	cout << " number of rectangles is ..." << n - nsq << endl ;

	int e = equalRectangles(ra, n) ;
	cout << "the number of rectangle in the array equal to ra[0] is " << e ;
	// TO DO ===================
	// (4) determine the rectangle with max area in the array
	// call the describe function for the rectangle in the array with largest area
	// assuming the rectangle with the largest area is ra[50] NOT CORRECT
	// your output should be
	cout << endl << "the rectangle with largest area is " << ra[largest(ra, n)].describe() ;
	// system("pause") ; // may be required to pause on your system
	return 0 ;
}

// calls the describe() function for each of the rectangles in the array rax
void displayRectangleArray (Rectangle rax[], int nx)
{
	for (int j = 0 ; j < nx; j++)
	{
		cout << rax[j].describe() << endl;
	}
}

// calls the two parameter constructor for each of the rectangles in the array rax
void fillRectangleArray (Rectangle rax[], int nx)
{
	for (int k = 0; k < nx; k++)
	{
		rax[k].setWidth(randomNum());
		rax[k].setLength(randomNum());
	}
}

// returns the number of squares in the Rectangle array
int nSquares(Rectangle rax[], int nx)
{
	int n = 0;
	for(int i=1;i<nx;i++)
	{
		if(rax[i].isSquare())n++;
	}
	return n;
}

// returns the number of rectangles in the Rectangle array that are equal to rax[0]
int equalRectangles(Rectangle rax[], int nx)
{
	int n = 0;
	for(int i=1;i<nx;i++)
	{
		if(rax[i].operator==(rax[0]))n++;
	}
	return n;
}

// returns number betweet 10 and 20
double randomNum()
{
	return ((rand() % 100 + 100)/10);
}

// returns larget rectangle
int largest(Rectangle rax[], int nx)
{
	int n = 0;
	for(int i=1;i<nx;i++)
	{
		if(rax[i].area()>rax[n].area())n=i;
	}
	return n;
}
