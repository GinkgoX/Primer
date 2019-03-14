#include<iostream>

using namespace std;

int main(){

	double* pd = new double[3];
	pd[0] = 0.1;
	pd[1] = 0.2;
	pd[2] = 0.3;
	
	cout << "The address of pd is " << pd << endl;
	cout << "The pd[0] is " << pd[0] << endl;
	pd = pd + 1;
	cout << "After adding 1, pd[0] is " << pd[0] << endl;
	pd = pd - 1;
	delete[] pd;
	
	return 0;
}

