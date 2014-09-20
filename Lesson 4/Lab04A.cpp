///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab04A.cpp
// Date: September 19, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    A collection of functions. One returns the number of digits in an
//    int. Another reverses number order. One checks is a word is a 
//	  palindrome. The forth checks the number of vowels in a string.
//	  the last checks the number of times a character is used in a
//	  string.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

int nDigits (int number);
int reverse(int input);
bool isPalindrome(string text);
int nVowels(string text);
bool isVowel(char letter);
int searchChar(char letter, string text);


//returns number of digits
int nDigits (int number)
{
	int length = 1;
	while (number /= 10)
	{
		length++;
	}
	return length;
}

//reverses number
int reverse(int input)
{
	bool negative = false;
	
	if (input < 0)
	{
		input=input*-1;
		negative = true;
	}
	int reversed=0;
	
	while(input > 0)
    {
    	reversed = reversed*10 + (input % 10);
    	input = input/10;
    }
    
    if(negative)reversed=reversed*-1;
    
	return reversed;
}

//checks if a word is a palindrome
bool isPalindrome(string text) 
{
	bool palindrome;
	
	if (equal(text.begin(), text.begin() + text.size()/2, text.rbegin()))
	{
    	return true;
	}
	else
	{
		return false;
	}
}

//counts the number of vowels
int nVowels(string text)
{
	int number = 0;
	
	for(int i = 0; i < text.size(); ++i)
	{
		if(isVowel(text[i]))
		{
			number++;
		}
	}
	
	return number;
}

//checks letter for vowel
bool isVowel(char letter)
{
	char vowels[10]={'a', 'A', 'e', 'E', 'I', 'i', 'o', 'O', 'u', 'U'};
	bool answer = false;
	
	for (int i = 0;i<10;i++)
	{
		if(letter==vowels[i])
		{
			answer = true;
		}
	}
	
	return answer;
}

//checks number of times a character appears in a string
int searchChar(char letter, string text)
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

int main ()
{
	int interger;
	string text;
	char character;
	bool test;
	
	//Function 1 & 2
	cout << "Enter a number: " ;
	cin >> interger;
	cout << "The number of digits in " << interger << " is " <<	nDigits(interger) << endl;
	cout << "The  reversed number of " << interger << " is " <<	reverse(interger) << endl;
	
	//Function 3 & 4
	cout << "Enter a word: " ;
	cin >> text;
	cout << "The word " << text << " is ";
	if(!isPalindrome(text))
	{
		cout << "not ";
	}
	cout << "a palindrome and contains " << nVowels(text) << " vowels." << endl;
	cin.clear();
    cin.ignore(1000, '\n');
    
    //Function 5
	cout << "Enter text: " ; 
	getline(cin,text);
	cout << "Enter character to search for: "; 
	cin >> character ; // 4 sample user input 
	cout << "there are(is) " << searchChar(character, text) << " " << character << " "
	<< " in " << text;
}
