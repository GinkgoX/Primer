#ifndef VECT_H_
#define VECT_H_

#include<cmath>
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	private:
		double x;
		double y;
		char mode;
		void set_x(double r, double theta);
		void set_y(double r, double theta);
	public:
		Vector();
		Vector(double x1, double y1, char form = 'r');
		void reset(double x1, double y1, char form = 'r');
		~Vector();
		
		void polar();
		void rect();
		
		double x_val()const {return x;}
		double y_val()const {return y;}
		double r_val()const {return sqrt(x * x + y * y);}
		double theta_val()const 
		{
			if(x == 0.0 && y == 0.0)
			{
				return 0.0;
			}
			else
			{
				return atan2(y,x);
			}
		}
			
		Vector operator+(const Vector &v)const;
		Vector operator-(const Vector &v)const;
		Vector operator-()const;
		Vector operator*(double n)const;
			
		friend Vector operator*(double n, const Vector &v);
		friend std::ostream & operator<<(std::ostream &os, const Vector &v);
	};
}

#endif


