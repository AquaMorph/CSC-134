///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab09.cpp
// Date: December 1, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Grade management program
//                                                                  
///////////////////////////////////////////////////////////////////////

 #include "Lab09.h"


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
	
	while(getline(infile, line).good())
	{
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
	out << setw(16) << left << "Student Name" << setw(11) << left << "Test Score" << "Grade" << endl;
	while(current != NULL)
	{
		string name = current->lastName + ", " + current->firstName;
		cout << setw(20) << left << name << setw(9) << left <<current->score << current->grade << endl;
		out << setw(20) << left << name << setw(9) << left <<current->score << current->grade << endl;
		current = current->next;
	}
}

//Displays all data
void highest(node *current)
{
	double high[7];
	string names[7];
	
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
		else if(current->score>high[5])
		{
			high[5]=current->score;
			names[5]=current->lastName + ", " + current->firstName;
		}
		else if(current->score>high[6])
		{
			high[6]=current->score;
			names[6]=current->lastName + ", " + current->firstName;
		}
		current = current->next;
	}
	
	cout << "\nHighest Test Score: " << high[0] << endl;
	cout << "Students having the highest test score:" << endl;
	out << "\nHighest Test Score: " << high[0] << endl;
	out << "Students having the highest test score:" << endl;
	for(int i=0;i<7;i++)
	{
		if(i>4)
		{
			if(high[i]==high[i-1])
			{
				cout << names[i] << endl;
				out << names[i] << endl;
			}
		}
		else
		{
			cout << names[i] << endl;
			out << names[i] << endl;
		}
	}
}

//Creates text file
void writeOpen()
{
	out.open("colglazierChristian.txt");
}

//Saves text file
void writeClose()
{
	out.close();
}
