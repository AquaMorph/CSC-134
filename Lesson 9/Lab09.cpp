///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab09.cpp
// Date: October 21, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Bank management program
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
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

void menu();
void subMenu();
void add(node *&head, node *&last);
int genAccount();
void addCustomer(node *&head, node *&last, string, string, double, double, int);
void processCustomer(node *current, int, int);
void printAll(node *current);
void loadUsers(node *&head, node *&last);
bool isEmpty(node *head);
void addFirst(node *&head, node *&last, string, string, double, double, int);
void remove(node *&head, node *&last);

//Prints menu
void menu()
{
	cout << "1: Enter 1 to add a new customer." << endl;
	cout << "2: Enter 2 for an existing customer." << endl;
	cout << "3: Enter 3 to print customers data." << endl;
	cout << "9: Enter 9 to exit the program." << endl;
}

//Prints sub menu
void subMenu()
{
	cout << "1: Enter 1 to make a deposit." << endl;
	cout << "2: Enter 2 to withdraw." << endl;
	cout << "3: Enter 3 to check balance." << endl;
	cout << "9: Enter 9 to exit." << endl;
}

//Creates a random account number
int genAccount()
{
	return rand() % 9000 + 1000;
}

//Checks to see if the node is already created
bool isEmpty(node *head)
{
	if(head == NULL)return true;
	else return false;
}

//Sets up the node and adds first entry
void addFirst(node *&head, node *&last, string name, string type, double amount, double rate, int account)
{
	node *temp = new node;
	temp->name = name;
	temp->type = type;
	temp->amount = amount;
	temp->rate = rate;
	temp->account = account;
	temp->next = NULL;
	head = temp;
	last = temp;
}

//Adds a customer to the node
void addCustomer(node *&head, node *&last, string name, string type, double amount, double rate, int account)
{
	if(isEmpty(head))addFirst(head, last, name, type, amount, rate, account);
	else
	{
		node *temp = new node;
		temp->name = name;
		temp->type = type;
		temp->amount = amount;
		temp->rate = rate;
		temp->account = account;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

//Promts usere with a menu to add an account
void add(node *&head, node *&last)
{
	string name, type;
	double amount, rate;
	int account = genAccount();
	cin.clear();
    cin.ignore(1000, '\n');
	cout << "Enter customer's name: ";
	getline(cin,name); 
    cout << name << endl;
	cout << "Enter account type (checking/savings): ";
	cin >> type;
	cout << "Enter amount to be deposited to open account: ";
	cin >> amount;
	cout << "Enter interest rate (as a percent): ";
	cin >> rate;
	cout << "Account number: " << account << endl;
	addCustomer(head, last, name, type, amount, rate, account);
}

//Removes account
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

void processCustomer(node *current, int account, int choice)
{
	double amount;
	if(choice==1)
	{
		while(current != NULL)
		{
			if(current->account==account)
			{
				cout << "Enter deposite amount: ";
				cin >> amount;
				current->amount = current->amount + amount;
			}
			current = current->next;
		}
	}
	if(choice==2)
	{
		while(current != NULL)
		{
			if(current->account==account)
			{
				cout << "Enter withdraw amount: ";
				cin >> amount;
				current->amount = current->amount - amount;
			}
			current = current->next;
		}
	}
	if(choice==3)
	{
		while(current != NULL)
		{
			if(current->account==account)
			{
				cout << "Account Holder Name: " << current->name << endl;
				cout << "Account Type: " << current->type << endl;
				cout << "Account Number: " << current->account << endl;
				cout << "Balance: " << current->amount << endl;
				cout << "Interest Rate: " << current->rate << endl;
				cout << "*****************************" << endl;
				cout << endl;
			}
			current = current->next;
		}		
	}
	
}

//Loads accounts from a text file
void loadUsers(node *&head, node *&last)
{
	string line,first,lastN,name,type;
	double amount,rate;
	int account;
	ifstream infile;
	infile.open("customers.txt");
	
	//checks for file opening
	if (!infile)
	{
		cout << "Cannot open the input file. Program terminates!" << endl;
		menuChoice=9;
	}
	
	while(infile.good())
	{
		getline(infile, line);
		stringstream stream(line);
		stream >> first;
		stream >> lastN;
		name=first+" "+lastN;
		stream >> type;
		stream >> amount;
		stream >> rate;
		account = genAccount();
		addCustomer(head, last, name, type, amount, rate, account);
		line.clear();
	}
}

//Displays all user data
void printAll(node *current)
{
	while(current != NULL)
	{
		cout << "Account Holder Name: " << current->name << endl;
		cout << "Account Type: " << current->type << endl;
		cout << "Account Number: " << current->account << endl;
		cout << "Balance: " << current->amount << endl;
		cout << "Interest Rate: " << current->rate << endl;
		cout << "*****************************" << endl;
		cout << endl;
		current = current->next;
	}
}

int main() 
{  
	node *head = NULL;
	node *last = NULL;
	loadUsers(head, last);
	int account;
	while(menuChoice!=9)
	{
		menu();
		cin >> menuChoice;
		if(menuChoice==1)
		{
			add(head,last);
		}
		if(menuChoice==2)
		{
			cout << "Enter account number: ";
			cin >> account;
			subMenuChoice=0;
			while(subMenuChoice!=9)
			{
				subMenu();
				cin >> subMenuChoice;
				processCustomer(head,account,subMenuChoice);
			}
			
		}
		if(menuChoice==3)
		{
			printAll(head);
		}
	}
	return 0;
}
