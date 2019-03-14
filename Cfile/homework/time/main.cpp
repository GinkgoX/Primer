#include<iostream>
#include"time.h"
using namespace std;

int main()
{
	Time planning;
	Time coding(1, 00);
	Time fixing(5, 00);
	Time total;
	
	cout << "planning time = ";
	cout << planning << endl;
	
	total = coding + fixing;
	cout << "coding + fixing = ";
	cout << total << endl;
	
	Time morefixing(2,30);
	total = morefixing.operator+(total);
	cout << "more time fixing for debug = ";
	cout << total << endl;
	
	Time lessfixing(1, 00);
	total = coding + fixing - lessfixing;
	cout << "less time fixing for debug = ";
	cout << total << endl;
	
	double n = 0.85;
	total = (coding + fixing)*n;
	cout << "efficient programer for debug = ";
	cout << total << endl;
	
	double m = 0.85;
	total = m*(coding + fixing);
	cout << "friend function for debug = ";
	cout << total << endl;
	
	return 0;
}

