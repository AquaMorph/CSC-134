///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab05A.cpp
// Date: October 3, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    A collection of functions. One returns the number of digits in an
//    string. Another reverses a string. One checks if a word is a 
//	  palindrome. The forth eliminates a letter from a string. Another
//	  searches for a character and returns the number of time it is used.
//	  The last checks the number of number used in a string.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int nChars(string);
string reverse(string);
bool isPalidrome(string);
int nIntegers(string);   
int searchChar(char,string);
string eraseChar(char, string);
bool isNumber(char);

//returns number ok characters in string
int nChars(string text)
{
	return text.length();
}

//revereses a string
string reverse(string text)
{
	string reversed= "";
	
	for(int i=0; i<text.length();i++)
	{
		reversed = text[i] + reversed;
	}
	
	return reversed;
}

//checks if a string is a palidrome
bool isPalidrome(string text)
{
	if (equal(text.begin(), text.begin() + text.size()/2, text.rbegin()))
	{
    	return true;
	}
	else
	{
		return false;
	}
	
}

//returns number of digits in a string
int nIntegers(string text)
{
	int number = 0;
	
	for(int i = 0; i < text.size(); ++i)
	{
		if(isNumber(text[i]))
		{
			number++;
		}
	}
	
	return number;
} 

//searches string for a character and returns number of times it appears
int searchChar(char letter,string text)
{
	int number = 0;
	
	for(int i = 0; i < text.size(); ++i)
	{
		if(letter==text[i])
		{
			number++;
		}
	}
	
	return number;
}

//erases a character from a string
string eraseChar(char letter, string text)
{
	string output;

	for(size_t i = 0; i < text.size(); ++i)
	{
	  	if(text[i] != letter)
		{
			output += text[i];
		}
	}
	
	return output;
}

//checks if a character is a number
bool isNumber(char letter)
{
	char num[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	bool answer = false;
	
	for (int i = 0;i<10;i++)
	{
		if(letter==num[i])
		{
			answer = true;
		}
	}
	
	return answer;
}

int main() 
{  
  // 1
  cout << nChars("Wake Tech CSC 134") << endl ;	// 17
  cout << nChars("1234AAA")<< endl ;			//  7
  cout << nChars("AaBb") << endl ;  		//  4
  cout << nChars("Aa   Bb") << endl ;  		//  7  Three blanks 
  // 2
  cout << reverse("12345")<< endl ;			// 54321 
  cout << reverse("Wake")<< endl ; 			// ekaW
  cout << reverse("CSC 134 Programming")<< endl ;	// gnimmargorP 431 CSC 
  // 3
  cout << isPalidrome("12Mom21") << endl ;	// false or 0 
  cout << isPalidrome("Dad") << endl ; 		// false or 0       
  cout << isPalidrome("MoM") << endl ; 		// true or 1 
  cout << isPalidrome("12MoM21") << endl ; 	// true or 1 
  // 4
  cout << nIntegers("CSC 134")<< endl ;		// 3 
  cout << nIntegers("C++ Programming")<< endl;  // 0 
  // 5
  cout << searchChar('6',"123466") << endl ; 			// 2 
  cout << searchChar('e',"Wake TECH")<< endl;			// 1 
  cout << searchChar('c',"Community College")<< endl ;	// 0 
  // 6
  cout << eraseChar('e', "Wake TECH Cee")<< endl ;		// "Wak TECH C" 
  cout << eraseChar('a', "aaaa 1234") << endl ; 		// 1234
	
  return 0 ;
}   // end of main 


