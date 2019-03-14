#include<iostream>
#include<cmath>
#include<cstring>
#include"meantp.h"

using namespace std;

class Demo
{
private:
	char word[40];
public:
	Demo(const char *str)
	{
		strcpy(word, str);
		cout << "Demo " << word << " created. " << endl;
	}
	~Demo()
	{
		cout << "Demo " << word << "destroyed. " << endl;
	}
	void show()const
	{
		cout << "Demo " << word << "lives. " << endl;
	}
};

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main()
{
	double x, y, z;
	Demo d1("found in main() ");
	cout << "Enter two numbers (Q or q to exit): ";
	while(cin >> x >> y)
	{
		try
		{
			z = means(x, y);
			cout << "The mean mean of " << "( " << x << " , " << y << " ) is " << z << endl;
			cout << "Enter next pair of numbers(Q or q to exit): "; 
		}
		catch(bad_hmean &bh)
		{
			bh.mesg();
			cout << "Try again ! " << endl;
			continue;
		}
		catch(bad_gmean &bg)
		{
			bg.mesg();
			cout << "Value used " << bg.x << " " << bg.y << endl;
			cout << "Sorry, you don't get to play anymore. " << endl;
			break;
		}
	}
	
	d1.show();
	cout << "done . " << endl;
	return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
	if(a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
	if(a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return sqrt(a*b);
}

double means(double a, double b) throw(bad_hmean, bad_gmean)
{
	double am, gm, hm;
	Demo d2("found in means() ");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch(bad_hmean &bh)
	{
		bh.mesg();
		cout << "Caught in means() " << endl; 
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}

