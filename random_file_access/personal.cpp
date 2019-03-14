#include<iostream>
#include<fstream>
#include<cstring>
#include"personal.h"

using namespace std;

Personal::Personal():nameLen(10), cityLen(10)
{
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
}

Personal::Personal(char *ssn, char *nm, char *ct, int y, long s):nameLen(10), cityLen(10)
{
	name = new char[nameLen + 1];
	city = new char[cityLen + 1];
	strcpy(SSN, ssn);
	strcpy(name, nm);
	strcpy(city, ct);
	year = y;
	salary = s;
}

void Personal::writeToFile(fstream &out) const
{
	out.write(SSN, 9);
	out.write(name, nameLen);
	out.write(city, cityLen);
	out.write(reinterpret_cast<const char*>(&year), sizeof(int));
	out.write(reinterpret_cast<const char*>(&salary), sizeof(long));
}

void Personal::readFromFile(fstream &in)
{
	in.read(SSN, 9);
	in.read(name, nameLen);
	in.read(city, cityLen);
	in.read(reinterpret_cast<const char *>(&year), sizeof(int));
	in.read(reinterpret_cast<const char *>(&salary), sizeof(long));
}

void Personal::readKey()
{
	char s[80];
	cout << "Enter SSN : ";
	cin.getline(s, 80);
	strncpy(SSN, s, 9);
}

ostream & Personal::writeLegibly(ostream &os)
{
	SSN[9] = name[nameLen] = city[cityLen] = '\0';
	os << "SSN = " << SSN << " , Nane = " << name << " , City = " << city << " , Year = " << year << " , Salary = " << salary ;
	return os;
}

istream & Personal::readFromConsole(istream &is)
{
	SSN[9] = name[nameLen] = city[cityLen] = '\0';
	char s[80];
	cout << "SSN : " ;
	is.getline(s, 80);
	strncpy(SSN, s, 9);
	cout << "Name : ";
	is.getline(s, 80);
	strncpy(name, s, nameLen);
	cout << "City : ";
	is.getline(s, 80);
	strncpy(city, s, cityLen);
	cout << "Birthyear : ";
	is >> year;
	cout << "Salary : ";
	is >> salary;
	is.ignore();
	return is;
}

