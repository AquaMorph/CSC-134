///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab01.cpp
// Date: August 29, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Ask for students name and grades. Then stores all that information 
//    and calculates a final grade.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() 
{
	string name;
    double quizzes[3];
    double labs[4];
    double midterm;
    double final;
    double grade;

	//Gets student's name
    cout << "Enter Student Name: ";
    getline(cin,name);
    
    //Gets quiz grades
    for(int i=0;i<3;i++)
    {
    	cout << "Enter quiz grade: ";
    	cin >> quizzes[i];
    }
    
    //Gets lab grades
    for(int i=0;i<4;i++)
    {
    	cout << "Enter lab grade: ";
    	cin >> labs[i];
    }
    
    //Gets midterm grade
    cout << "Enter Midterm Exam grade: ";
    cin >> midterm;
    
    //Gets final grade
    cout << "Enter Final Exam grade: ";
    cin >> final;
    
    //Calculated and prints total grade
	grade = midterm*.2 + final*.2 + ((quizzes[0]+quizzes[1]+quizzes[2])/3)*.1 + ((labs[0]+labs[1]+labs[2]+labs[3])/4)*.5;
    cout << name << " your Final Semester Grade for the class is " << grade << endl;

    return 0;
}

