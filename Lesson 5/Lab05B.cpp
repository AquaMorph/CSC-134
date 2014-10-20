///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab05B.cpp
// Date: October 10, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    A collection of functions. One returns if a string has repeating
//    characters. Another converts a string to uppercase. A thrid checks 
//	  the number of words in a string. The forth checks if two strings
//	  are the same in a noncase sensitive manor. The fifth one returns
//	  the position a string appears in another string. The last one counts
//	  the number of letters in a string.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool repeatsChar(string);
string upperCase(string); 
int nWords(string); 
bool equals (string, string); 
int subString(string,string);
int nAlpha(string); 

//checks for repeating characters
bool repeatsChar(string text)
{
	char letters[36]={'A','B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3',
	'4','5','6','7','8','9','0'};
	bool repeats = false;
	int count[36]={0};

	for(int i=0;i<text.length();i++)
	{
		for(int j=0;j<36;j++)
		{
			if(toupper(text[i])==letters[j])count[j]++;
		}
		
	}
	for(int i=0;i<36;i++)
	{
		if(count[i]>1)repeats=true;
	}
	return repeats;
}

//returns string to uppercase
string upperCase(string text)
{
	for(int i=0;i<text.length();i++)
	{
		text[i]=toupper(text[i]);
	}
	return text;
}

//checks number if words in a string
int nWords(string text)
{
	int count = 1;
    for(int i = 0; i < text.length();i++)
    {
    	if(text[i] == ' '&&text[i+1] != ' ')count++;
    }
    return count;
}

//returns is two stings are equal to each other
bool equals (string text1, string text2)
{
	if(upperCase(text1)==upperCase(text2))return true;
	else return false;
}

//check position a string appears in another string
int subString(string sub,string text)
{
	int count=0, total=-1;
	for(int i = 0; i < text.length();i++)
	{
		for(int j = 0; j < sub.length();j++)
		{
			if(text[i+j]==sub[j])count++;
		}
		if(count==sub.length())
		{
			total=i;
			count=0;
		}
		else count=0;
	}
	return total;
}

//counts number off letters in a string
int nAlpha(string text)
{
	char letters[26]={'A','B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int count = 0;
	for(int i = 0; i < text.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if(toupper(text[i])==letters[j])count++;
		}
	}
	return count;
}

int main() 
{  
	// 7
	cout << repeatsChar(" Wake TECH" )<< endl ; 			// true or 1 
	cout << repeatsChar(" Wake 101" ) << endl ; 			// true or 1 
	cout << repeatsChar("AbCD") << endl ; 					// false or 0 
	// 8 
	cout << upperCase("123 CSC programs")<< endl ;		 	// 123 CSC PROGRAMS 
	cout << upperCase("123 CSC ") << endl ; 				// 123 CSC
	cout << upperCase("abD34 CSC ") << endl ; 				// ABD34 CSC

	// 9 
	cout << nWords("Outside it is raining today" )<< endl;	// 5
	cout << nWords("Outside" ) << endl ; 					// 1
	cout << nWords("Outside       CSC")  << endl ; 			// 2   
	cout << nWords("Mary's decision's--accepted")  << endl ;// 2   
	// 10
	cout << equals ("ATE","ate") << endl ; 					// true or 1
	cout << equals ("1234", "2314") << endl 	;			// false or 0
	// 11
	cout << subString("rogr","C++ Programming") << endl ; 	// 5  
	cout << subString("C++","C++ Programming") << endl ; 	// 0 
	cout << subString("ror","C++ Programming") << endl ;    // -1 
	// 12
	cout << nAlpha("CSC 134") << endl ; 					//	3 
	cout << nAlpha("123134") << endl ; 						// 0 
	cout << nAlpha("Wake  Tech") << endl ; 					// 8 
	
  return 0 ;
}   // end of main 


