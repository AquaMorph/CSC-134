///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab06B.cpp
// Date: October 19, 2014
// Programmer: Christian Colglazier  
//
// Description:
//    Inputs data from a text file parses data into several arrays and
//	  then calculated averages of the data.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
const int SIZE = 40;
const int COLUMN = 5;
string name[SIZE];
void getData(ifstream& inf, string n[], double tstData[][COLUMN], int count);
void calculateAverage(double tstData[][COLUMN], int count);
void calculateGrade(double tstData[][COLUMN], char gr[], int count);
void print(string n[], double tstData[][COLUMN], char gr[], int count);

void getData(ifstream& inf, string n[], double tstData[][COLUMN], int count)
{
	string line;
	int i = 0;
	//parses each line into an array
	while(inf.good())
	{
		getline(inf, line);
		stringstream stream(line);
		stream >> n[i];
		stream >> tstData[i][0];
		stream >> tstData[i][1];
		stream >> tstData[i][2];
		stream >> tstData[i][3];
		i++;
	}
}

void calculateAverage(double tstData[][COLUMN], int count)
{
	//averages each country
	for(int i=0;i<SIZE;i++)
	{
		tstData[i][4]=(tstData[i][0]+tstData[i][1]+tstData[i][2]+tstData[i][3])/4;
	}
}

void calculateGrade(double tstData[][COLUMN], char gr[], int count)
{
	//finds letter value for each country
	for(int i=0;i<SIZE;i++)
	{
		if(tstData[i][4]>80)gr[i]='N';
		else if(tstData[i][4]>60)gr[i]='L';
		else if(tstData[i][4]>50)gr[i]='R';
		else gr[i]='H';
	}
}

void print(string n[], double tstData[][COLUMN], char gr[], int count)
{
	double average=0;
	
	//output headers
	cout << setw(20) << left << "Name" << setw(8) << left << "1990" <<
	setw(8) << left << "2000" << setw(8) << left << "2005" <<
	setw(8) << left << "2012" << setw(8) << left << "Average" <<
	setw(8) << left << "Grade" << endl;
	
	//print loop
	for(int i=0;i<count;i++)
	{
		average=average+tstData[i][4];
		cout << setw(20) << left << n[i] << setw(8) << left << tstData[i][0] <<
		setw(8) << left << tstData[i][1] << setw(8) << left << tstData[i][2] <<
		setw(8) << left << tstData[i][3] << setw(8) << left << tstData[i][4] <<
		setw(8) << left << gr[i] << endl;
	}
	
	//total average
	average=average/count;
	cout << '\n' << "Group Ages 15-24 Years Old Employment Average: " << average << endl;
}
  
int main()
{
	string names[SIZE];
    double testData[SIZE][COLUMN];
    char grade[SIZE];

    ifstream inFile;

    inFile.open("employed_15-24yrsOld.txt");

    if (!inFile)
    {
        cout << "Cannot open the input file: ch8_Ex13Data.txt." << endl;
        cout << "Program terminates!" << endl;
        return 1;
    }

    cout << fixed << showpoint << setprecision(2);

    getData(inFile, names, testData, SIZE);
    calculateAverage(testData, SIZE);
    calculateGrade(testData, grade, SIZE);
    print(names, testData, grade, SIZE);

    inFile.close();

	return 0;
}

