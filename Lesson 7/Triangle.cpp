 // Triangle.cpp  
 #include "Triangle.h"
  
	// default constructor set all sides = 1 
	Triangle::Triangle()  { s1 = 1; s2 = 1; s3 = 1 ; }   
       
	//  constructor all sides = x 
	Triangle::Triangle(int x) 
	{ 
	  s1 = x; 
	  s2 = x; 
	  s3 = x ;	
	}	
	// constructor s1 == x, s2 == y s3 == z 
	Triangle::Triangle(int x, int y, int z) 
	{  
		  s1= x ; s2 = y ; s3= z ;  
	} 
	
		  
 // ==========================================
  // class methods
	double Triangle::area() 
	{ 
		double s = perimeter();
		double a = sqrt(s*(s-s1)*(s-s2)*(s-s2));
		return a;
	} 
	
	// compute perimeter DONE
	int Triangle::perimeter() { int p = s1 + s2 + s3;  return p;  }  
    
	// getters DONE
	int Triangle::getSide1() { return s1 ; } 
	int Triangle::getSide2() { return s2 ; } 
	int Triangle::getSide3() { return s3 ; } 
  
	// setters DONE
	void Triangle::setSide1(int x) { s1 = x ;  } 
	void Triangle::setSide2(int x) { s2 = x ;  } 
	void Triangle::setSide3(int x) { s3 = x ;  } 
  
	int Triangle::largestSide()
	{
		int max = s1;
		if(s2>max)max=s2;
		if(s3>max)max=s3;
		return max;
	}  

	int Triangle::smallestSide ()
	{
		int min = s1;
		if(s2<min)min=s2;
		if(s3<min)min=s3;
		return min;
	}	
	
	bool  Triangle::isRight()
	{
		bool b = false;
		if(pow(largestSide(),2)==pow(smallestSide(),2)
			+pow((perimeter()-largestSide()-smallestSide()),2))b=true;
		return b;
	} 
		
	string Triangle:: typeTriangle ()
	{
		string s = "Not sure";
		if(isTriangle())
		{
			if(s1 == s2 && s2 == s3 && s3 == s1) s = "Equilateral";
			else if(s1 == s2 || s2 == s3 || s3 == s1) s = "Isosceles";
			else if(s1 != s2 && s2 != s3 && s3 != s1) s = "Scalene";
		}
		return s;
	} 
		
	bool  Triangle::isTriangle ()
	{
		bool b = false;
		if(largestSide()<(perimeter()-largestSide()))b=true;
		return b;
	} 
			
	// is Triangle a == Triangle b ??		
	bool Triangle::operator==( const Triangle other)  
	{	
		bool b = false ;
		if (s1 == other.s1 && s2 == other.s2 && s3 == other.s3) b = true;
		return b ; 
	
	} 
	string Triangle::describe() 
	{ 
		stringstream ss;
		string s ; 
		ss << " [" << s1 << " " << s2  << " " << s3 << " ] "  ;
		s = ss.str();
		return s; 
	}  
  

