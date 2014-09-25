///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab04B.cpp
// Date: September 25, 2014
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
int getIndex(int index, int i); 
bool repeatsDigit(int number);
int largest(int digits);
int smallest(int digits);
double average(int digits);

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

int getIndex(int index, int digits)
{
	int numDig =nDigits(digits)-1;
	
	if(index>numDig)return -1;
	else
	{
		int number[numDig];
		
		for(int i=numDig;i>=0;i--)
		{
			number[i] = digits % 10;
			digits = digits / 10;
		}
		return number[index];
	}
}

bool repeatsDigit(int digits)
{
	int numDig =nDigits(digits)-1;
	int number[numDig];
	bool value = false;
		
	for(int i=numDig;i>=0;i--)
	{
		number[i] = digits % 10;
		digits = digits / 10;
	}
	
	for(int i = 0;i<=numDig;i++)
	{
		if(number[i]==number[i-1]) value=true;
	}
	return value;
}

int largest(int digits)
{
	int numDig =nDigits(digits)-1;
	int number[numDig];
	int largest = digits % 10;
		
	for(int i=numDig;i>=0;i--)
	{
		number[i] = digits % 10;
		digits = digits / 10;
	}
	
	for(int i = 0;i<numDig;i++)
	{
		if(number[i]>=largest) largest=number[i];
	}
	
	return largest;
}

int smallest(int digits)
{
	int numDig =nDigits(digits)-1;
	int number[numDig];
	int smallest = digits % 10;
		
	for(int i=numDig;i>=0;i--)
	{
		number[i] = digits % 10;
		digits = digits / 10;
	}
	
	for(int i = 0;i<numDig;i++)
	{
		if(number[i]<=smallest) smallest=number[i];
	}
	
	return smallest;
}

double average(int digits)
{
	int numDig =nDigits(digits)-1;
	int number[numDig];
	int sum=0;
	double avg;
		
	for(int i=numDig;i>=0;i--)
	{
		number[i] = digits % 10;
		digits = digits / 10;
	}
	
	for(int i = 0;i<=numDig;i++)
	{
		sum=sum+number[i];
	}
	
	avg=sum/(double)(numDig+1);
	
	return avg;
}

int main ()
{
	int interger, index;
	
	//Function 1
	cout << "Enter a number: " ;
	cin >> interger;
	cout << "Enter an index: " ;
	cin >> index;
	cout << "The digit at index " << index << " is " <<	getIndex(index,interger) << endl;
	
	//Function 2
	cout << "Enter a number: " ;
	cin >> interger;
	cout << "The number " << interger << " does ";
	if(!repeatsDigit(interger))
	{
		cout << "not ";
	}
	cout << "have repeating numbers." << endl;
	
	//Function 3 & 4
	cout << "Enter a number: " ;
	cin >> interger;
	cout << "The largest number in " << interger << " is " << largest(interger);
	cout << " while the smallest is " << smallest(interger) << endl;
    
    //Function 5
	cout << "Enter a number: " ;
	cin >> interger;
	cout << "The average of the interger in the number " << interger << " is " << average(interger);
}
