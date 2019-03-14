#include<iostream>
#include<cstdlib>

using namespace std;

double hmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Enter two numbers : ";
	while(cin >> x >> y)
	{
		z = hmean(x, y);
		cout << "Harmonic mean of " << "( " << x << " ,  " << y << " )" << " is " << z << endl;
		cout << "Enter next set of number(Q or q to exit): ";
	}
	cout << "done . " << endl;
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
	{
		cout << "Untenable arguments to hmean() . " << endl;
		abort(); 
	}
	return 2.0 * a * b / ( a + b);
}



