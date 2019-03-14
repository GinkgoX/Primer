
#include<cmath>
#include"vect.h"
using namespace std;
namespace VECTOR
{
	const double unit_rad = 45.0 / atan(1.0);
		
	void Vector::set_x(double r, double theta)
	{
		x = r*cos(theta);
	}
		
	void Vector::set_y(double r, double theta)
	{
		y = r*sin(theta);
	}
	
	Vector::Vector()
	{
		x = y =  0;
		mode = 'r';
	}

	Vector::Vector(double x1, double y1, char form)
	{
		mode = form;
		if(mode == 'r')
		{
			x = x1;
			y = y1; 
		}
		else if(mode == 'p')
		{
			set_x(x1, y1);
			set_y(x1, y1);
		}
		else
		{
			cout << "Wrong type mode. Set vector = 0" << endl;
			x = y = 0;
			mode = 'r';
		}
	}
		
	void Vector::reset(double x1, double y1, char form)
	{
		mode = form;
		if(mode == 'r')
		{
			x = x1;
			y = y1; 
		}
		else if(mode == 'p')
		{
			set_x(x1, y1);
			set_y(x1, y1);
		}
		else
		{
			cout << "Wrong type mode. Set vector = 0" << endl;
			x = y = 0;
			mode = 'r';
		}
	}
	Vector::~Vector()
	{
	
	}

	void Vector::polar()
	{
		mode = 'p';
	}
	
	void Vector::rect()
	{
		mode = 'r';
	}
		
	Vector Vector::operator+(const Vector &v)const
	{
		return Vector(x + v.x, y + v.y);
	}
	
	Vector Vector::operator-(const Vector &v)const
	{
		return Vector(x - v.x, y - v.y);
	}
		
	Vector Vector::operator-()const
	{
		return Vector(-x, -y);
	}	
	
	Vector Vector::operator*(double n)const
	{
		return Vector(x*n, y*n);
	}
		
	Vector operator*(double n, const Vector &v)
	{
		return Vector(n*v);
	}

	std::ostream & operator<<(std::ostream &os, const Vector &v)
	{	
		if(v.mode == 'r')
		{
			os << "Rectangle System : (x, y) = " << "( " <<  v.x << " , " << v.y <<" )";
		}
		else if(v.mode == 'p')
		{
			os << "Polar System : (r, theta) = " << "(" << v.r_val() << " , " << v.theta_val()*unit_rad << " )";
		}
		else
		{
			os << "I can't recognize the system, Please check your system mode . ";
		}
		return os;
	}
}
