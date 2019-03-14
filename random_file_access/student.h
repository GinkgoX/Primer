#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
#include<fstream>
#include"personal.h"

using namespace std;

class Student: public Personal
{
protected:
	const int majorLen;
	char *major;
	ostream & writeLegibly(ostream &os);
	friend ostream & operator<<(ostream &os, const Student &s)
	{
		return s.writeLegibly(os);
	}
	istream & readFromConsole(istream &is);
	friend istream & operator>>(istream &is, Student &s)
	{
		return s.readFromConsole(is);
	}
public:
	Student();
	Student(char *ssn, char *nm, char *ct, int y, long s, char *mj);
	int size() const
	{
		return Personal::size() + majorLen;
	}
	void writeToFile(fstream &out)const;
	void readFromFile(fstream &in);
};

#endif
