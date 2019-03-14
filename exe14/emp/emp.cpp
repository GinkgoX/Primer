#include<iostream>
#include"emp.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Abstr_emp::Abstr_emp():fname("Null"), lname("Null"), job("Null")
{

}

Abstr_emp::Abstr_emp(const string &fn, const string &ln, const string &j):fname(fn), lname(ln), job(j)
{

}

void Abstr_emp::showAll()const
{
	cout << fname << " " << lname << " 's job : " << job << endl;
}

void Abstr_emp::setAll()
{
	cout << "Enter the first name : " ;
	getline(cin, fname);
	cout << "Enter the last name : " ;
	getline(cin, lname);
	cout << "Enter the job : ";
	getline(cin, job);
}

ostream & operator<<(ostream &os, const Abstr_emp &e)
{
	os << e.fname << " " << e.lname << " 's job : " << e.job << endl;
	return os;
}

Abstr_emp::~Abstr_emp()
{

}

Employee::Employee():Abstr_emp()
{

}

Employee::Employee(const string &fn, const string &ln, const string &j):Abstr_emp(fn, ln, j)
{
	
}

void Employee::showAll()const
{
	Abstr_emp::showAll();
}

void Employee::setAll()
{
	Abstr_emp::setAll();
}

Manger::Manger():Abstr_emp()
{

}

Manger::Manger(const string &fn, const string &ln, const string &j, int ico):inchargeof(ico), Abstr_emp(fn, ln, j)
{

}

Manger::Manger(const Abstr_emp &e, int ico):inchargeof(ico), Abstr_emp(e)
{

}

Manger::Manger(const Manger &m):Abstr_emp(m)
{
	
}

void Manger::getCharge()
{
	cout << "Enter numbers of in charge : ";
	cin >> inchargeof;
}

void Manger::showAll()const
{
	Abstr_emp::showAll();
	cout << "in charge of : " << inchargeof << endl;
}

void Manger::setAll()
{
	Abstr_emp::setAll();
	getCharge();
}

Fink::Fink():Abstr_emp()
{

}

Fink::Fink(const string &fn, const string &ln, const string &j, const string &rpo):reportsto(rpo), Abstr_emp(fn, ln, j)
{

}

Fink::Fink(const Abstr_emp &e, const string &rpo):reportsto(rpo), Abstr_emp(e)
{

}

Fink::Fink(const Fink &f):Abstr_emp(f)
{

}

void Fink::getReport()
{	
	cin.get();
	cout << "Enter the report story : ";
	getline(cin, reportsto);
}

void Fink::showAll()const
{
	Abstr_emp::showAll();
	cout << "report story : " << reportsto << endl;
}

void Fink::setAll()
{
	Abstr_emp::setAll();
	getReport();
}

HighFink::HighFink():Abstr_emp(), Manger(), Fink()
{

}

HighFink::HighFink(const string &fn, const string &ln, const string &j, int ico, const string &rpo):Abstr_emp(fn, ln, j), Manger(fn, ln, j, ico), Fink(fn, ln, j, rpo)
{

}

HighFink::HighFink(const Abstr_emp &e, int ico, const string &rpo):Abstr_emp(e), Manger(e, ico), Fink(e, rpo)
{

}

HighFink::HighFink(const Manger &m, const string &rpo):Abstr_emp(m), Manger(m), Fink(m, rpo)
{

}

HighFink::HighFink(const Fink &f, int ico):Abstr_emp(f), Manger(f, ico), Fink(f)
{

}

HighFink::HighFink(const HighFink &h):Abstr_emp(h), Manger(h), Fink(h)
{

}

void HighFink::showAll()const
{
	Abstr_emp::showAll();
	cout << "in charge of : " << Manger::charge() << endl;
	cout << "report story : " << Fink::report() << endl;
}

void HighFink::setAll()
{
	Abstr_emp::setAll();
	Manger::getCharge();
	Fink::getReport();
}
