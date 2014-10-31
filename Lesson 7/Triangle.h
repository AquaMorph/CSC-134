// Triangle.h 
#include <string>
#include <iostream>
#include <sstream> 
#include <math.h> 
#include <stdlib.h>   

using namespace std; 

class Triangle
{
public:
	// three constructors 
	Triangle();						// default constructor 
	Triangle(int x);				// constructor all sides are the same 
	Triangle(int x, int y, int z);  // constructor with three parameters 
	
	// getters 
	int getSide1();
	int getSide2();
	int getSide3();
	
	// setters 
	void setSide1(int x);				
	void setSide2(int x); 
	void setSide3(int x); 
	
	double area();	  	   // returns the area 
	int perimeter();	   // returns the perimeter 
	string describe();	   // returns a string with the triange properties in the format [s1 s2 s3] 
	int largestSide();     // returns the largest side		
	int smallestSide();    // returns the smallest side	  
	bool isRight();		   // returns true if the Triangle is a right triangle 
	string typeTriangle(); // returns the type of Triangle "equilateral", "right Triangle", "scalene", isoceles	
	bool  isTriangle();	   // returns true if the three sides can form a triangle	 
	bool operator==(const Triangle other);	// const == do not change anything 
	  
private:
	int s1;  // side 1
	int s2 ; // side 2 
	int s3 ; // side 3 
}; // end class Triangle  

