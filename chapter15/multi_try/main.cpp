#include<iostream>
#include<cmath>
#include"meantp.h"

using namespace std;

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
	double x, y, z;
	cout << "Enter two numbers : ";
	while(cin >> x>> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << "( " << x << " , " << y << " )" << " is " << z << endl;
			cout << "Geometric mean of " << "( " << x << " , " << y << " )" << " is " << gmean(x, y) << endl;
			cout << "Enter next set of number(Q or q to exit) : ";
		}
		catch(bad_hmean &bh)
		{
			bh.mesg();
			cout << "Try again . " << endl;
			continue;
		}
		catch(bad_gmean &bg)
		{
			cout << bg.mesg();
			cout << "values used : " << "( " << bg.x << " , " << bg.y << " )" << endl;
			cout << "You don't get to play play any more . \n";
			break;
		}
	}
	cout << "done . " << endl;
	return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
	if(a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b) ; 
}

double gmean(double a, double b) throw(bad_gmean)
{
	if(a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return sqrt(a*b);
}

