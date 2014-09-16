// function example
#include <iostream>
using namespace std;

int nDigits (int a)
{
	int length = 1;
	while ( a /= 10 )
	{
		length++;
	}
	return length;
}

int main ()
{
  int z;
  z = nDigits (9247);
  cout << "The result is " << z;
}
