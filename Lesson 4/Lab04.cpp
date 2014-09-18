#include <iostream>
#include <string>
#include <algorithm>
#include <array>
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
	
}

bool isVowel(char letter)
{
	char vowels[10]={'a', 'A', 'e', 'E', 'I', 'i', 'o', 'O', 'u', 'U'};
	bool answer = false;
	
	for (int i = 0;i<9;i++)
	{
		if(letter==vowels[i])
		{
			answer = true;
		}
	}
	
	return answer;
}

int main ()
{
  string z;
  z = isPalindrome ("ran");
  cout << "The result is " << z;
}
