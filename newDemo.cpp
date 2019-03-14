#include<iostream>

using namespace std;

int main(){

	int* pt = new int;
	*pt = 1024;
	cout << "The value of *pt is " << *pt <<" and the location is "<< &pt <<endl;
	cout << "The size of *pt is " << sizeof(*pt) << " and the size of pt is " << sizeof(pt) << endl;
	
	double* pd = new double;
	*pd = 2048.20438;
	cout << "The value of *pt is " << *pd <<" and the location is "<< &pd << endl;
	cout << "The size of *pt is " << sizeof(*pd) << " and the size of pt is " << sizeof(pd) << endl;
	
	char flower[10] = "roise";
	cout << flower << "s are red " << endl;
	
	delete pt;
	delete pd;
	return 0;
}

