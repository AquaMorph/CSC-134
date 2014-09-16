///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab03B.cpp
// Date: September 12, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Asks for the number of flyers in the group and for each persons
//    seat number. Then calculates total price and taxes.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() 
{
	int number, seat;
    double total=0.0;
    double tax;
    
    //checks login info
    cout << "Welcome to Wake's Traveling Agency" << endl;
    cout << "How many people are in your traveling party? ";
	cin >> number;

    
    //displays menu and asks for an order
    for(int i =1; i<=number;i++)
    {
    	cout << "First Class: (1-20) - $400" << endl;
		cout << "Coach A: (21-40)- $250" << endl;
		cout << "Emergency Exit: (41-44) - $225" << endl;
		cout << "Coach B: (45-65) - $275" << endl;
		cout << "Emergency Exit: (66-69) - $225" << endl;
		cout << "Coach C: (70-90) - $275" << endl;
		cout << "Which Seat Number would you like for traveler " << i << "? ";
		cin >> seat;
		if(1<=seat&&seat<=20)total+=400;
		else if(21<=seat<=40)total+=250;
		else if(41<=seat<=44)total+=225;
		else if(45<=seat<=65)total+=275;
		else if(66<=seat<=69)total+=225;
		else if(70<=seat<=90)total+=275;
    }
    
    //displays total
    tax=total+(total*.0475);
    cout << "The total amount of money that the group of " << number << " should pay is $" << total << endl;
    cout << "Total after taxes: &" << tax;
    
    return 0;
}
