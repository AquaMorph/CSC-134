///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab06A.cpp
// Date: October 19, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Inputs data from a text file and reformats it to another text file
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum class_level {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

namespace tys
{
	class_level deriveClassLevel(int num_of_credits)
	{
		class_level level;
		if(num_of_credits<=29)level = class_level::FRESHMAN;
		else level = class_level::SOPHOMORE;
		return level;
	}
}
namespace fys
{
	class_level deriveClassLevel(int num_of_credits)
	{
		class_level level;
		if(num_of_credits<=29)level = class_level::FRESHMAN;
		else if(num_of_credits<=59) level = class_level::SOPHOMORE;
		else if(num_of_credits<=89) level = class_level::JUNIOR;
		else level = class_level::SENIOR;
		return level;
	}
	
}
int main() 
{  
	using namespace fys;
	ifstream infile;
	infile.open("student_status.txt");
	ofstream outlife;
	outlife.open("student_new_status.txt");
	string line,first,first2,last,id,year,out,credits;
	int hours;
	
	//checks for file opening
	if (!infile)
	{
		cout << "Cannot open the input file. Program terminates!" << endl;
		return 1;
	}
	while(infile.good())
	{
		getline(infile, line);
		stringstream stream(line);
		stream >> last;
		stream >> first;
		stream >> first2;
		first = first + " " + first2;
		getline(infile, line);
		stream.clear();
		stringstream stream2(line);
		stream2 >> id;
		stream2 >> hours >> credits;
		switch(deriveClassLevel(hours))
		{
			case FRESHMAN:
				year="Freshman";
				break;
			case SOPHOMORE:
				year="Sophomore";
				break;
			case JUNIOR:
				year="Junior";
				break;
			case SENIOR:
				year="Senior";
				break;
		}
		out = last + " " + first + " " + id + " " + std::to_string(hours);
		outlife << out << hours << " " << year << '\n';
		cout << out << hours << " " << year << endl;
	}
	
	infile.close();
	outlife.close();
  return 0 ;
}

