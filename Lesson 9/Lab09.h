///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab09.h
// Date: December 1, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Grade management program
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <math.h>
#include <stdlib.h>   

using namespace std;

struct node
{
	string lastName;
	string firstName;
	double score;
	char grade;
	node *next;
};

ofstream out;

void add(node *&head, node *&last);
char getGrade(double);
void addStudent(node *&head, node *&last, string, string, double, char);
void printAll(node *current);
void loadUsers(node *&head, node *&last);
bool isEmpty(node *head);
void addFirst(node *&head, node *&last, string, string, double, char);
void remove(node *&head, node *&last);
void highest(node *current);
void writeOpen();
void writeClose();
