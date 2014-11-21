///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: triangleMain.cpp
// Date: October 31, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Hangles calculations with triangles
//                                                                  
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Triangle.cpp"

void displayTriangleArray (Triangle tax[], int nx) ; 
void fillTriangleArray (Triangle tax[], int nx) ; 
// return a triangle 
Triangle maxPerimeter(Triangle tax[], int nx) ; // return the traingle with the largest perimeter
using namespace std;  

// function main begins program execution
int main()
{     
	Triangle t1;            // default constructor   all sides == 1
	cout << "enter side for triangle t2..." ;  
	int s;
	cin >> s;  
	Triangle t2(s);			// one parameter constructor all sides == s 
	Triangle t3(2, 3, 4);	// three parameter constructor s1 == 2 s2 == 3  s3 == 4 
	Triangle t4(10,33,5);	// three parameter constructor s1 == 10 s2 == 33  s3 == 5 NOT a triangle 
	
	//Triangle 1
	cout << "triangle t1 perimeter is: "  <<  t1.perimeter() << endl ;
	cout << " and its sides are..." 
		 <<  t1.getSide1() << "  "  << t1.getSide2() << "  " << t1.getSide3() << endl;
	cout << "triangle t1 area is: " << t1.area() << endl;
	cout << "triangle t1 largest side is: " << t1.largestSide() << endl;
	cout << "triangle t1 smallest side is: " << t1.smallestSide() << endl;
	if(t1.isTriangle())cout << t1.describe() << " is a " << t1.typeTriangle() << " triange" << endl;
	else cout << "t1 is not a triangle" << endl;
	if(t1.isRight())cout << "triangle t1 is a right triangle" << endl;
	
	//Triangle 2
	cout << "\ntriangle t2 perimeter is: "  <<  t2.perimeter() << endl ;
	cout << " and its sides are..." 
		 <<  t2.getSide1() << "  "  << t2.getSide2() << "  " << t2.getSide3() << endl;
	cout << "triangle t2 area is: " << t2.area() << endl;
	cout << "triangle t2 largest side is: " << t2.largestSide() << endl;
	cout << "triangle t2 smallest side is: " << t2.smallestSide() << endl;
	if(t2.isTriangle())cout << t2.describe() << " is a " << t2.typeTriangle() << " triange" << endl;
	else cout << "t2 is not a triangle" << endl;
	if(t2.isRight())cout << "triangle t2 is a right triangle" << endl;
	
	//Triangle 3
	cout << "\ntriangle t3 perimeter is: "  <<  t3.perimeter() << endl ;
	cout << " and its sides are..." 
		 <<  t3.getSide1() << "  "  << t3.getSide2() << "  " << t3.getSide3() << endl;
	cout << "triangle t3 area is: " << t3.area() << endl;
	cout << "triangle t3 largest side is: " << t3.largestSide() << endl;
	cout << "triangle t3 smallest side is: " << t3.smallestSide() << endl;
	if(t3.isTriangle())cout << t3.describe() << " is a " << t3.typeTriangle() << " triange" << endl;
	else cout << "t3 is not a triangle" << endl;
	if(t3.isRight())cout << "triangle t3 is a right triangle" << endl;
	
	//Triangle 4	 
	cout << "\ntriangle t4 perimeter is: "  <<  t4.perimeter() << endl ;
	cout << " and its sides are..." 
		 <<  t4.getSide1() << "  "  << t4.getSide2() << "  " << t4.getSide3() << endl;
	cout << "triangle t4 area is: " << t4.area() << endl;
	cout << "triangle t4 largest side is: " << t4.largestSide() << endl;
	cout << "triangle t4 smallest side is: " << t4.smallestSide() << endl;
	if(t4.isTriangle())cout << t4.describe() << " is a " << t4.typeTriangle() << " triange" << endl;
	else cout << "t4 is not a triangle" << endl;
	if(t4.isRight())cout << "triangle t4 is a right triangle" << endl;
	cout << endl;
	 		 
	//checks for equal triangles
	if (t1 == t2 && t2 == t3 && t3 == t4) { cout << "all equal"; }
	else if (t1 == t2 || t2 == t3 || t3 == t4) { cout << "two are equal" ;  }
	else { cout << "none equal ";}
	
	//largest triangle
	string largest = " ";
	double large = 0.0;
	if(t1.isTriangle())
	{
		if(large<t1.area())
		{
			large=t1.area();
			largest = "t1";
		}
	}
	if(t2.isTriangle())
	{
		if(large<t2.area())
		{
			large=t2.area();
			largest="t2";
		}
	}
	if(t3.isTriangle())
	{
		if(large<t3.area())
		{
			large=t3.area();
			largest = "t3";
		}
	}
	if(t4.isTriangle())
	{
		if(large<t4.area())
		{
			large=t4.area();
			largest = "t4";
		}
	}
	cout << "The largest triangle is " << largest << " with and area of " << large << endl;
		  
	cout << endl << endl ; 
		  
    // AARAY of TRIANGLES 
    int n = 50; 
    Triangle ta[n]; 
    // default cnstructors
    cout << "before calling setters..." << endl ; 
    cout << "Display triangles in the array..." << endl ; 
    displayTriangleArray ( ta, n) ;
    
    // fill the array with the setters 
    cout << endl << "fill the array with instances of triangles..." << endl ; 
	fillTriangleArray ( ta, n) ;

    cout << "Display triangles in the array AFTER..." << endl ; 
    displayTriangleArray ( ta, n) ;
    
    //finds smallest triangle
    cout << "smallest triangle..." << maxPerimeter(ta, n).describe() << endl;
	
	//finds equal triangles
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			if(i!=j)
			{
				if(ta[i]==ta[j])cout << "Triangle t" << i+1 << " equals " << "t" << j+1 << endl;
			}
		}
	} 
	
	//display the number of equilateral isosceles and scalene triangles
	int equ=0,iso=0,sca=0;
	for(int j = 0 ; j < n; j++)
	{		
		if(ta[j].typeTriangle()=="Equilateral")equ++;
		if(ta[j].typeTriangle()=="Isosceles")iso++;
		if(ta[j].typeTriangle()=="Scalene")sca++;
	}
	cout << "Equilateral: " << equ << " Isosceles " << iso << " Scalene " << sca << endl;


    // system("pause") ; // may be required to pause on your system 
	   	return 0 ; 
} // end main

void displayTriangleArray (Triangle tax[], int nx) 
{  
	for (int j = 0 ; j < nx; j++)  
	{  
		cout << tax[j].describe() << endl ;   
	}
}

void fillTriangleArray (Triangle tax[], int nx) 
{
	for (int k = 0; k < nx; k++)
	{
    	tax[k].setSide1(rand() % 9 +2); 
		tax[k].setSide2(rand() % 9 +2); 
		tax[k].setSide3(rand() % 9 +2); 
    }
}
 
Triangle maxPerimeter(Triangle tax[], int nx) 
{
	double min=99999;
	int minimum;
	for (int j = 0 ; j < nx; j++)  
	{  
		if(tax[j].area()<min)
		{
			min=tax[j].area();
			minimum=j;
		} 
	}
	return tax[minimum];
}
