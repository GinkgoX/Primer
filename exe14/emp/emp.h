#ifndef EMP_H_
#define EMP_H_

#include<iostream>
#include<cstring>

using std::string;
using std::ostream;

class Abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	Abstr_emp();
	Abstr_emp(const string &fn, const string &ln, const string &j);
	virtual void showAll()const;
	virtual void setAll();
	friend ostream & operator<<(ostream &os, const Abstr_emp &e);
	virtual ~Abstr_emp() = 0;
};

class Employee:public Abstr_emp
{
public:
	Employee();
	Employee(const string &fn, const string &ln, const string &j);
	virtual void showAll()const;
	virtual void setAll();
};

class Manger:virtual public Abstr_emp
{
private:
	int inchargeof;
protected:
	int charge() const{return inchargeof;};
	int & charge(){return inchargeof;};
public:
	Manger();
	Manger(const string &fn, const string &ln, const string &j, int ico = 0);
	Manger(const Abstr_emp &e, int ico);
	Manger(const Manger &m);
	void getCharge();
	virtual void showAll()const;
	virtual void setAll();
};

class Fink:virtual public Abstr_emp
{
private:
	string reportsto;
protected:
	const string report()const{return reportsto;};
	string & report(){return reportsto;};
public:
	Fink();
	Fink(const string &fn, const string &ln, const string &j, const string &rpo);
	Fink(const Abstr_emp &e, const string &rpo);
	Fink(const Fink &f);
	void getReport();
	virtual void showAll()const;
	virtual void setAll();
};

class HighFink:public Manger, public Fink
{
public:
	HighFink();
	HighFink(const string &fn, const string &ln, const string &j, int ico, const string &rpo);
	HighFink(const Abstr_emp &e, int ico, const string &rpo);
	HighFink(const Manger &m, const string &rpo);
	HighFink(const Fink &f, int ico);
	HighFink(const HighFink &h);
	virtual void showAll()const;
	virtual void setAll();
};
#endif




