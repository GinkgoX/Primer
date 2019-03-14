#include<iostream>
#include"winec.h"

using namespace std;

int main()
{
	cout << "Enter name of wine : ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter the number of years : ";
	int yrs;
	cin >> yrs;
	
	Wine holding(lab, yrs);
	holding.getBottles();
	holding.show();
	
	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {49, 60 ,72};
	Wine more("Gushing Graph Red", YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.label() << " : " << more.sum() << endl;
	cout << "done . " << endl;
	return 0;
}

