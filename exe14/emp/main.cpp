#include<iostream>
#include"emp.h"

using namespace std;

int main()
{
	Employee em("A", "B", "C");
	cout << em << endl;
	em.showAll();
	
	Manger ma("Am", "Bm", "Cm", 4);
	cout << ma << endl;
	ma.showAll();
	
	Fink fk("Af", "Bf", "Cf", "Df");
	cout << fk << endl;
	fk.showAll();
	
	HighFink hk("Ah", "Bh", "Ch", 4, "Dh");
	cout << hk << endl;
	hk.showAll();
	
	HighFink h1(ma, "Ef");
	h1.showAll();
	
	HighFink h2;
	h2.setAll();
	
	cout << "Using Abstr_emp pointer : " << endl;
	Abstr_emp *tri[4] = {&em, &ma, &fk, &hk};
	for(int i = 0; i < 4; i++)
	{
		tri[i]->showAll();
	}
	
	cout << "done . " << endl;
	return 0;
}







