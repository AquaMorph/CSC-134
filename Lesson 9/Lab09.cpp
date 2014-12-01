///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab09.cpp
// Date: October 21, 2014
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



void add(node *&head, node *&last);
char getGrade(double);
void addStudent(node *&head, node *&last, string, string, double, char);
void printAll(node *current);
void loadUsers(node *&head, node *&last);
bool isEmpty(node *head);
void addFirst(node *&head, node *&last, string, string, double, char);
void remove(node *&head, node *&last);
void highest(node *current);


//Returns letter grade of score
char getGrade(double score)
{
	if(score>=90)return 'A';
	else if(score>=80)return 'B';
	else if(score>=70)return 'C';
	else if(score>=60)return 'D';
	else return 'F';
}

//Checks to see if the node is already created
bool isEmpty(node *head)
{
	if(head == NULL)return true;
	else return false;
}

//Sets up the node and adds first entry
void addFirst(node *&head, node *&last, string lastName, string firstName, double score, char grade)
{
	node *temp = new node;
	temp->lastName = lastName;
	temp->firstName = firstName;
	temp->score = score;
	temp->grade = grade;
	temp->next = NULL;
	head = temp;
	last = temp;
}

//Adds a student to the node
void addStudent(node *&head, node *&last, string lastName, string firstName, double score, char grade)
{
	if(isEmpty(head))addFirst(head, last, lastName, firstName, score, grade);
	else
	{
		node *temp = new node;
		temp->lastName = lastName;
		temp->firstName = firstName;
		temp->score = score;
		temp->grade = grade;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

//Removes student
void remove(node *&head, node *&last)
{
	if(isEmpty(head));
	else if (head == last)
	{
		delete head;
		head = NULL;
		last = NULL;
	}
	else {
		node *temp = head;
		head = head->next;
		delete temp;
	}
}


//Loads accounts from a text file
void loadUsers(node *&head, node *&last)
{
	string line,lastName,firstName;
	double score;
	char grade;
	ifstream infile;
	infile.open("Ch9_Ex2Data.txt");
	
	//checks for file opening
	if (!infile)
	{
		cout << "Cannot open the input file. Program terminates!" << endl;
	}
	
	while(infile.good())
	{
		getline(infile, line);
		stringstream stream(line);
		stream >> firstName;
		stream >> lastName;
		stream >> score;
		grade = getGrade(score);
		addStudent(head, last, lastName, firstName, score, grade);
		line.clear();
	}
}

//Displays all data
void printAll(node *current)
{
	cout << setw(16) << left << "Student Name" << setw(11) << left << "Test Score" << "Grade" << endl;
	while(current != NULL)
	{
		string name = current->lastName + ", " + current->firstName;
		cout << setw(20) << left << name << setw(9) << left <<current->score << current->grade << endl;
		current = current->next;
	}
}

//Displays all data
void highest(node *current)
{
	double high[5];
	string names[5];
	
	while(current != NULL)
	{
		if(current->score>high[0])
		{
			high[0]=current->score;
			names[0]=current->lastName + ", " + current->firstName;
		}
		else if(current->score>high[1])
		{
			high[1]=current->score;
			names[1]=current->lastName + ", " + current->firstName;
		}
		else if(current->score>high[2])
		{
			high[2]=current->score;
			names[2]=current->lastName + ", " + current->firstName;
		}
		else if(current->score>high[3])
		{
			high[3]=current->score;
			names[3]=current->lastName + ", " + current->firstName;
		}
		else if(current->score>high[4])
		{
			high[4]=current->score;
			names[4]=current->lastName + ", " + current->firstName;
		}
		current = current->next;
	}
	
	cout << "Highest Test Score: " << high[0] << endl;
	cout << "Students having the highest test score:" << endl;
	for(int i=0;i<5;i++)
	{
		cout << names[i] << endl;
	}
}

int main() 
{  
	node *head = NULL;
	node *last = NULL;
	loadUsers(head, last);
	printAll(head);
	cout << endl;
	highest(head);
	return 0;
}
