///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Rectangle.cpp
// Date: December 11, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Hangles calculations with rectangles
//                                                                  
///////////////////////////////////////////////////////////////////////
#include "Rectangle.h"
// constructors =============================
// default constructor set sides = 1
Rectangle::Rectangle()
{
	l = 1;
	w = 1;
}

 // constructor l and w = x
Rectangle::Rectangle(double x)
{
 	l = x;
	w = x;
}
 // constructor
Rectangle::Rectangle(double x, double y)
{
	l = x;
	w = y;
}
 
Rectangle::Rectangle(Rectangle& rx)
{
 	l = rx.getLength();
 	w = rx.getWidth();
}

// ==========================================
// class functions
double Rectangle::area()
{
	double a = 0.0; 
	a = l*w; 
	return a; 
}

double Rectangle::perimeter()
{
	double p = 2*(l + w);
	return p;
}
// compute perimeter DONE

double Rectangle::diagonal() 
{
	double d = sqrt(l*l + w*w);
	return d;
}
// return the diagonal of the rectangle
// INCORRECT
// use c^2 = l^2 + w^2
// getters and setters DONE
double Rectangle::getLength()
{
	return l;
}
double Rectangle::getWidth() 
{
	return w;
}
void Rectangle::setLength(double x) 
{ 
	l = x;
}
void Rectangle::setWidth(double x) 
{
	w = x;
}

double Rectangle::largestSide ()
{
	double max = l;
	if(w>l)max =w;
	return max;
}

double Rectangle::smallestSide () 
{
	int min = l;
	if(w<l)min = w;
	return min;
}

bool Rectangle::isEmpty() 
{
	bool b = false;
	if(l*w==0)b = true;
	return b;
}

bool Rectangle::isSquare()
{
  bool b = false; 
  if(w==l)b=true;
  return b;
}

string Rectangle:: typeRectangle ()
{
	string s = "Not sure";
	if(isEmpty());
	else if(isSquare())s= "square";
	else s= "rectangle";
	return s;
}

bool Rectangle::operator==( const Rectangle other)
{
	bool b = false;
	if (l == other.l && w == other.w) b = true;
	return b;
}

string Rectangle::describe()
{
	stringstream ss;
	string s ;
	ss << " length = " << getLength() << " width = " << getWidth()
	 << " area = " << area() << " perimeter = " << perimeter ()
 	<< "type = " << typeRectangle() << " diagonal = " << diagonal();
 	s = ss.str();
 	return s;
}
