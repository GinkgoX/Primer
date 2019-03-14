#include<iostream>
#include"compx.h"


Compx::Compx()
{
	real = image = 0;
}

Compx::Compx(double r, double i)
{
	real = r;
	image = i;
}

Compx::~Compx()
{
	
}

Compx Compx::operator+(const Compx &c)
{
	return Compx(real + c.real, image + c.image);
}

Compx Compx::operator-(const Compx &c)
{
	return Compx(real - c.real, image - c.image);
}


Compx Compx::operator*(const Compx &c)
{
	return Compx(real*c.real - image*c.image, real*c.image + image*c.real);
}

Compx Compx::operator ~()const
{
	
	return Compx(real, -image);
}

ostream & operator<<(ostream &os, const Compx &c)
{
	os << "(" << c.real << " , " <<  c.image << "i )";
	return os;
}

istream & operator>>(istream &is, Compx &c)
{
	std::cout << "\nReal : ";
	if(is >> c.real)
	{
		std::cout << "Image : ";
		is >> c.image;
	}
	return is;
}


