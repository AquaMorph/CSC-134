///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab02.cpp
// Date: September 5, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Ask for name and property cost and expensives. Then stores all  
//    that information and calculates a final sale price for $22000 of 
//	  profit.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() 
{
	string name;
    double expenses[7];
    double sumExpenses;
    double investment;
    double sale;
    
    //Gets investment
    cout << "Enter the purchase price of the investment property: $";
    cin >> investment;
    cin.clear();
    cin.ignore(1000, '\n');
    
	//Gets person's name
    cout << "Enter your Name: ";
    getline(cin,name);
    
    //Get expenses
    cout << "List of Expenses" << endl;
    cout << "Enter the cost of repairing kitchen: $";
    cin >> expenses[0];
    cout << "Enter the cost of repairing bathrooms: $";
    cin >> expenses[1];
    cout << "Enter the cost of repairing floors: $";
    cin >> expenses[2];
    cout << "Enter the cost of landscape: $";
    cin >> expenses[3];
    cout << "Enter the cost of painting: $";
    cin >> expenses[4];
    cout << "Enter the cost of repairing the plumbing: $";
    cin >> expenses[5];
    cout << "Enter the cost of replacing the light fixtures: $";
    cin >> expenses[6];
    
    //Calculates and prints
    sumExpenses=expenses[0]+expenses[1]+expenses[2]+expenses[3]+expenses[4]
	+expenses[5]+expenses[6];
	sale=(22000+(investment + sumExpenses))/.94;
    cout << name << " the sale price of the property should be: $" << sale;

    return 0;
}
