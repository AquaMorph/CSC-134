///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab03A.cpp
// Date: September 12, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Checks for correct login info. Then displays a menu and calculates 
//    a total price.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() 
{
	string password;
	string username;
    double total=0.0;
    bool login=false;
    char menu;
    
    //checks login info
    while(login==false)
    {
    	cout << "Username: ";
  		cin >> username;
  		cout << "Password: ";
  		cin >> password;
		if(username == "wiseguy" && password=="opensesame")login=true;
    }
    
    //displays menu and asks for an order
    while(menu!='Q')
    {
    	cout << "A: Turkey, Red Potato Salad, Sada -$5.60" << endl;
		cout << "B: Roast Beef, Chili Beans, Soda -$4.75" << endl;
		cout << "C: Bologna, Green Salad, Water - $4.50" << endl;
		cout << "D: Ham, Portuguese Beands, Soda - $6.20" << endl;
		cout << "Q: Quit" << endl;
		cout << "Enter your selection: ";
		cin >> menu;
		menu=toupper(menu);
		if(menu=='A')total+=5.60;
		if(menu=='B')total+=4.75;
		if(menu=='C')total+=4.50;
		if(menu=='D')total+=6.20;
    }
    
    //displays total
    cout << "The total of the order is $" << total;
    
    return 0;
}
