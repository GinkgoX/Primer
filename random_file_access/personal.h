#ifndef PERSONAL_H_
#define PERSONAL_H_

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Personal
{
private:
	const int nameLen, cityLen;
	char SSN[10], *name, *city;
	int year;
	long salary;
	ostream & writeLegibly(ostream &out);
	friend ostream & operator<<(ostream &out, Personal &p)
	{
		return p.writeLegibly(out);
	}
	istream & readFromConsole(istream &in);
	friend istream & operator>>(istream &in, Personal &p)
	{
		return p.readFromConsole(in);
	}
public:
	Personal();
	Personal(char *ssn, char *nm, char *ct, int y, long s);
	void writeToFile(fstream &out)const;
	void readFromFile(fstream &in);
	void readKey();
	int size() const
	{
		return 9 + nameLen + cityLen + sizeof(year) + sizeof(salary);
	}
	bool operator==(const Personal &p)const
	{
		return strncpy(p.SSN, SSN, 9) == 0;
	}
};

#endif

