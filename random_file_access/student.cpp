#include<iostream>
#include<fstream>
#include<cstring>
#include"student.h"

using namespace std;

Student::Student():majorLen(10)
{
	Personal::Personal();
	major = new char[majorLen + 1];
}

Student::Student(char *ssn, char *nm, char *ct, int y, long s, char *m):majorLen(11)
{
	Personal(ssn, nm, ct, y, s);
	major = new char[majorLen + 1];
	strcpy(major, m);
}

ostream & Student::writeLegibly(ostream &os)
{
	Personal::writeLegibly(os);
	major[majorLen] = '\0';
	os << " , Major : " << major;
	return os;
}

istream & Student::readFromConsole(istream &is)
{
	personal::readFromConsole(is);
	char s[80];
	cout << "Major : ";
	cin.getline(s, 80);
	strncpy(major, s, majorLen);
	return is;
}

void Student::writeToFile(fstream &out)const
{
	Personal::writeToFile(out);
	out.write(major, majorLen);
}

void Student::readFromFile(fstream &in)
{
	Personal::readFromFile(in);
	in.read(major, majorLen);
}





