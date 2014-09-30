#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int nChars(string) ;
int reverse(string) ;
bool isPalidrome(string) ;
int nIntegers(string) ;   
int searchChar(char,string) ;
bool repeatsChar(string) ;
string upperCase(string )  ; 
string eraseChar(char, string)  ;
int nWords(string ) ; 
bool equals (string, string ) ; 
int subString(string,string) ;
int nAlpha(string )  ; 



int main() 
{  
  // 1

  cout << nChars("Wake Tech CSC 134") << endl ;	// 17
  cout << nChars("1234AA")<< endl ;			//  7
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
  // 7
  cout << repeatsChar(" Wake TECH" )<< endl ; 			// true or 1 
  cout << repeatsChar(" Wake 101" ) << endl ; 			// true or 1 
  cout << repeatsChar("AbCD") << endl ; 				// false or 0 
  // 8 
  cout << upperCase("123 CSC programs")<< endl ; 	// 123 CSC PROGRAMS 
  cout << upperCase("123 CSC ") << endl ; 		// 123 CSC
  cout << upperCase("abD34 CSC ") << endl ; 		// ABD34 CSC

  // 9 
  cout << nWords("Outside it is raining today" )<< endl;	// 5
  cout << nWords("Outside" ) << endl ; 				// 1
  cout << nWords("Outside       CSC")  << endl ; 		// 2   
  cout << nWords("Mary's decision's--accepted")  << endl ; 	// 2   
  // 10
  cout << equals ("ATE","ate") << endl ; 			// true or 1
  cout << equals ("1234", "2314") << endl 	;		// false or 0
  // 11
  cout << subString("rogr","C++ Programming") << endl ; 	// 5  
  cout << subString("C++","C++ Programming") << endl ; 	// 0 
  cout << subString("ror","C++ Programming") << endl ;       // -1 
  // 12
  cout << nAlpha("CSC 134") << endl ; 				//  3 
  cout << nAlpha("123134") << endl ; 				// 0 
  cout << nAlpha("Wake  Tech") << endl ; 				// 8 

  return 0 ;
}   // end of main 


