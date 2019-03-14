#include<iostream>
#include"winec.h"

using std::cin;
using std::cout;
using std::endl;

Wine::Wine(const char *l, int y, const int yr[], const int bot[]):string(l), yrs(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{

}

Wine::Wine(const char *l, int y):string(l), yrs(y)
{

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
	PairArray::setPair(yr, bt);
}

string & Wine::label()
{
	return (string &)*this;
}

int Wine::sum()const
{	
	return PairArray::sumPair();
}

void Wine::show()const
{
	cout << "Wine : " << (string &)*this << endl;
	cout << "	" << "Year" << "	" << "Bottles" << endl;
	PairArray::showPair(yrs);
}

