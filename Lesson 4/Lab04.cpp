#include <iostream>
#include <string>
#include <algorithm>
#include <array>

bool isVowel(char letter);
using namespace std;

int nDigits (int number)
{
	int length = 1;
	while (number /= 10)
	{
		length++;
	}
	return length;
}

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

bool isPalindrome(string text) 
{
	bool palindrome = false;
	
	if (text == string(text.rbegin(), text.rend()))
	{
    palindrome == true;
	}
	
	return palindrome;
}

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
	char ch ;
	string s ; 
	cout << "Enter string " ; 
	cin >> s ; 
	cout << "Enter character to search for "; 
	cin >> ch ; // 4 sample user input 
	cout << "there are(is) " << searchChar(ch, s) << " " << ch << " "
	<< " in " << s;
}
