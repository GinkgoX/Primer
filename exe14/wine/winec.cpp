#include<iostream>
#include"winec.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
{
	name = l;
	yrs = y;
	yb.setPair(ArrayInt(yr, yrs), ArrayInt(bot, yrs));
}

Wine::Wine(const char *l, int y)
{
	name = l;
	yrs = y;
}

void Wine::getBottles()
{
	ArrayInt yr(yrs), bt(yrs);
	for(int i = 0; i < yrs; i++)
	{
		cout << "Enter year : ";
		cin >> yr[i];
		cout << "Enter bottles for that year : ";
		cin >> bt[i];
	}
	while(cin.get() != '\n')
	{
		continue;
	}
	yb.setPair(yr, bt);
}

string & Wine::label()
{
	return name;
}

void Wine::show()const
{
	cout << "Wine name : " << name << endl;
	cout << "	Year : " << "	Bottle : " << endl;
	yb.showPair(yrs);
}

int Wine::sum()const
{
	return yb.sumPair();
}

