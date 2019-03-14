#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include<iostream>
#include<fstream>
#include<string>

using std::string;
using std::ostream;
using std::ofstream;
using std::ifstream;

enum classId{employee, manager, fink, highFink};

class base_emp
{
private:
	string name;
	string job;
public:
	base_emp():name("none"), job("none"){};
	base_emp(const string &nm, const string &jb):name(nm), job(jb){};
	virtual ~base_emp() = 0 ;
	virtual void showAll()const;
	virtual void setAll();
	virtual void writeAll(ofstream &os);
	virtual void readAll(ifstream &is);
	friend ostream & operator<<(ostream &os, const base_emp &be);
};

class Employee:public base_emp
{
public:
	Employee():base_emp(){};
	Employee(const string &nm, const string &jb):base_emp(nm, jb){};
	virtual void showAll()const{base_emp::showAll();};
	virtual void setAll(){base_emp::setAll();};
	void writeAll(ofstream &os);
	void readAll(ifstream &is);
};

class Manager:virtual public base_emp
{
private:
	int inchargeof;
protected:
	int inChargeOf()const{return inchargeof;};
	int & inChargeOf(){return inchargeof;};
	void fileChargeOf(ofstream &os)const{os << "In charge of : " << inchargeof << " \t";};
	void fileChargeOf(ifstream &is){is >> inchargeof;};
public:
	Manager():base_emp(),inchargeof(0){};
	Manager(const string &nm, const string &jb, int ic):base_emp(nm, jb), inchargeof(ic){};
	Manager(const base_emp &be, int ic):base_emp(be), inchargeof(ic){};
	Manager(const Manager &m):base_emp(m){inchargeof = m.inchargeof;};
	virtual void showAll()const;
	virtual void setAll();
	void writeAll(ofstream &os);
	void readAll(ifstream &is);
};

class Fink:virtual public base_emp
{
private:
	string report;
protected:
	const string Report()const{return report;};
	string & Report(){return report;};
	void fileReport(ofstream &os){os << "Report : " << report;};
	void fileReport(ifstream &is){is >> report;};
public:
	Fink():base_emp(), report("none"){};
	Fink(const string &nm, const string &jb, const string rpt):base_emp(nm, jb), report(rpt){};
	Fink(const base_emp &be, const string &rpt):base_emp(be), report(rpt){};
	Fink(const Fink &f):base_emp(f){report = f.report;};
	virtual void showAll()const;
	virtual void setAll();
	void writeAll(ofstream &os);
	void readAll(ifstream &is);
};

class HighFink:public Manager, public Fink
{
public:
	HighFink(){};
	HighFink(const string &nm, const string &jb, int ic, const string &rpt):base_emp(nm, jb), Manager(nm, jb, ic), Fink(nm, jb, rpt){};
	HighFink(const base_emp &be, int ic, const string &rpt):base_emp(be), Manager(be, ic), Fink(be, rpt){};
	HighFink(const Manager &m, const string &rpt):base_emp(m), Manager(m), Fink(m, rpt){};
	HighFink(const Fink &f, int ic):base_emp(f), Manager(f, ic), Fink(f){};
	HighFink(const HighFink &h):base_emp(h), Manager(h), Fink(h){};
	virtual void showAll()const;
	virtual void setAll();
	void writeAll(ofstream &os);
	void readAll(ifstream &is);
};
#endif
