#include<iostream>
#include<fstream>
#include"employee.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

base_emp::~base_emp()
{

}

void base_emp::showAll()const
{
	cout << "	Name : " << name << "	Job : " << job;
}

void base_emp::setAll()
{
	cout << "Enter the name : " ;
	getline(cin, name);
	cout << "Enter the job : ";
	getline(cin, job);
}

void base_emp::writeAll(ofstream &os)
{
	os << "	Name : " << name << "	Job : " << job ;
}

void base_emp::readAll(ifstream &is)
{
	getline(is, name);
	getline(is, job);
}

ostream & operator<<(ostream &os, const base_emp &be)
{
	os << "	Name : " << be.name << "	Job : " << be.job << endl;
	return os;
}

void Employee::writeAll(ofstream &os)
{
	os << employee;
	base_emp::writeAll(os);
	os << endl;
}

void Employee::readAll(ifstream &is)
{
	base_emp::readAll(is);
}

void Manager::showAll()const
{
	base_emp::showAll();
	cout << "	In charge of : " << inchargeof << endl;	
}

void Manager::setAll()
{
	base_emp::setAll();
	cout << "Enter the inchargeof : ";
	cin >> inchargeof;
}

void Manager::writeAll(ofstream &os)
{
	os << manager;
	base_emp::writeAll(os);
	os << "	In charge of : " << inchargeof << endl;
	os << endl;
}

void Manager::readAll(ifstream &is)
{
	base_emp::readAll(is);
	is >> inchargeof;
}

void Fink::showAll()const
{
	base_emp::showAll();
	cout << "	Report : " << report << endl;
}

void Fink::setAll()
{
	base_emp::setAll();
	cout << "Enter the report : ";
	getline(cin, report);
}

void Fink::writeAll(ofstream &os)
{
	os << fink;
	base_emp::writeAll(os);
	os << "	Report : " << report << endl;
	os << endl;
}

void Fink::readAll(ifstream &is)
{
	base_emp::readAll(is);
	is >> report;
}

void HighFink::showAll()const
{
	base_emp::showAll();
	cout << "	In charge of : " << Manager::inChargeOf();
	cout << "	Report : " << Fink::Report() << endl;	
}

void HighFink::setAll()
{
	int ic;
	string rpt;
	base_emp::setAll();
	cout << "Enter the inchargeof : ";
	cin >> ic;
	inChargeOf() = ic;
	cin.get();
	cout << "Enter the report : ";
	getline(cin, rpt);
	Report() = rpt;
}

void HighFink::writeAll(ofstream &os)
{
	os << highFink;
	base_emp::writeAll(os);
	Manager::fileChargeOf(os);
	Fink::fileReport(os);
	os << endl;
}

void HighFink::readAll(ifstream &is)
{
	base_emp::readAll(is);
	Manager::fileChargeOf(is);
	Fink::fileReport(is);
}
