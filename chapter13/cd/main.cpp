#include<iostream>
#include"cd.h"

using namespace std;

void Bravo(const Cd &cd);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano Sonata in B flat, Fantasia in C . ", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	
	cout << "Using object directly : \n";
	
	c1.report();
	cout << endl;
	c2.report();
	cout << endl;
	
	cout << "Using type Cd * pointer to object : \n";
	
	pcd->report();
	cout << endl;
	pcd = &c2;
	pcd ->report();
	
	cout << "Calling a function with a Cd reference argument : \n";
	Bravo(c1);
	Bravo(c2);
	
	cout << "Testing assignment : \n";
	Classic copy;
	copy = c2;
	copy.report();
	cout << endl;
	
	return 0;
}

void Bravo(const Cd &cd)
{
	cd.report();
	cout << endl;
}
