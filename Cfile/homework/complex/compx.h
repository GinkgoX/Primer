#ifndef COMPX_H_
#define COMPX_H_

#include<iostream>
using namespace std;
class Compx
{
private:
	double real;
	double image;
public:
	Compx();
	Compx(double r, double i);
	~Compx();
	
	Compx operator+(const Compx &c);
	Compx operator-(const Compx &c);
	Compx operator*(const Compx &c);
 	Compx operator~()const;
	friend ostream & operator<<(ostream &os, const Compx &c);
	friend istream & operator>>(istream &is, Compx &c);
};

#endif
