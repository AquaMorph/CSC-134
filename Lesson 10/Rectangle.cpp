// Rectangle.cpp
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
 // INCORRECT fix
 Rectangle::Rectangle(Rectangle& rx)
 {
 	l = rx.getLength();// copy from l from rx NOT implemented
 	w = rx.getWidth();// copy the w from rx not implemented
 }

// ==========================================
 // class functions
 double Rectangle::area() { double a = 0.0; return a; }
 // compute the area of Rectangle
 // current Implementation is INCORRECT
 double Rectangle::perimeter() { double p = 2*(l + w); return p; }
 // compute perimeter DONE

 double Rectangle::diagonal() { double d = 0.0 ; return d; }
 // return the diagonal of the rectangle
 // INCORRECT
 // use c^2 = l^2 + w^2
 // getters and setters DONE
 double Rectangle::getLength() { return l; }
 double Rectangle::getWidth() { return w; }

void Rectangle::setLength(double x) { l = x ; }
void Rectangle::setWidth(double x) { w = x ; }

 double Rectangle::largestSide () { double max = 0 ; return max ; }
 // INCORRECT fix
 // function should return the larger of l and w

 double Rectangle::smallestSide () { int min = 0 ; return min ; }
 // INCORRECT fix
 // function should return the smaller of l and w 
  bool Rectangle::isEmpty() { bool b = false; return b ; }
 // return true if the area of rectangle is 0.0 otherwise return false
 // INCORRECT fix

 bool Rectangle::isSquare() { bool b = false; return b ; }
 // return true if the rectangle is a square ( l == w) otherwise return false
 // INCORRECT fix

 string Rectangle:: typeRectangle () {string s = "Not sure" ; return s ; }
 // return "square" if l == w
 // otherwise return “rectangle”
 // make sure isSquare() and isEmpty() is called
 // INCORRECT fix


 bool Rectangle::operator==( const Rectangle other) // are two rectangles equal ?
 {
 bool b = false ;
 if (l == other.l && w == other.w ) b = true;
 return b ;

 }
 string Rectangle::describe()
 {
 stringstream ss;
string s ;
 ss << " length = " << getLength() << " width = " << getWidth()
 << " area = " << area() << " perimeter = " << perimeter ()
 << "type = " << typeRectangle() << " diagonal = " << diagonal() ;
 return s;
}
