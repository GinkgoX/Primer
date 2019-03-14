#include<iostream>
#include"tennis.h"

using namespace std;

int main()
{
	TableTennisPlayer tp("Yang", "Nike", false);
	RatePlayer rp(1024, "Jnue","Marry",true);
	tp.name();
	if(tp.hasTable())
	{
		cout << " : has a table . " << endl;
	}
	else
	{
		cout << " : has not a table . " << endl;
	}
	rp.name();
	if(rp.hasTable())
	{
		cout << " : has a table . " << endl;
	}
	else
	{
		cout << " : has not a table . " << endl;
	}
	RatePlayer rp1(2048, tp);
	//derivated object recall base public method
	rp1.name();
	if(rp1.hasTable())
	{
		cout << " : has a table , " ;
	}
	else
	{
		cout << " : has not a table , " ;
	}
	cout << "the rating : " << rp1.rating() << endl;
	
	//base reference refers to derivated object(implicit expression)
	TableTennisPlayer &rt = rp;
	cout << "the reference recall: ";
	rt.name();
	cout << endl;
	
	//base pointer points to derivated object(implicit expression)
	TableTennisPlayer *pt = &rp;
	cout << "the pointer recall : ";
	pt->name();
	cout << endl;
	return 0;
}

