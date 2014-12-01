///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab09Main.cpp
// Date: December 1, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Grade management program
//                                                                  
///////////////////////////////////////////////////////////////////////
#include "Lab09.cpp"

int main() 
{  
	node *head = NULL;
	node *last = NULL;
	writeOpen();
	loadUsers(head, last);
	printAll(head);
	highest(head);
	writeClose();
	return 0;
}
