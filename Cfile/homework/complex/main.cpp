#include<iostream>
#include"compx.h"

using namespace std;

int main()
{
	Compx a(3.0, 4.0);
	Compx c;
	cout << "Enter a complex number :(q or Q to quit): ";
	while(cin >> c)
	{
		cout << "c is : " << c << endl;
		cout << "c's comjudate is : " << ~c << endl;
		cout << "a + c is : " << a + c << endl;
		cout << "a - c is : " << a - c << endl;
		cout << "a * c is : " << a*c << endl;
		a = Compx(2.0, 0.0);
		cout << "2 * c is : " << a*c << endl;
		cout << "ente a new complex number(q/Q to quit):";
	} 
	return 0;
}

