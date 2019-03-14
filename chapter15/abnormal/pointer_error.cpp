#include<iostream>
#include<cfloat>

using namespace std;

bool hmean(double a, double b, double *ans);

int main()
{
	double x, y, z;
	cout << "Enter two number : ";
	while(cin >> x >> y)
	{
		if(hmean(x, y, &z))
		{
			cout << "Harmonic mean of " << "( " << x << " , " << y << " )" << " is " << z << endl;
		}
		else
		{
			cout << "One value should not be negative of the other one, - Try again . " << endl;
		}
		cout << "Enter next set of number(Q or q to exit) : ";
	}
	cout << "done . " << endl;
	return 0;
}

bool hmean(double a, double b, double *ans)
{
	if(a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

