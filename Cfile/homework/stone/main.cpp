#include<iostream>
#include"stone.h"

int main()
{
	using namespace std;
	Stone poppins(2, 2.8);
	double p_wr = poppins;
	cout << "Convert to double => Poppins: " << p_wr << " pounds.\n";
	cout << "Convert to int => Poppins: " << int(poppins) << " pounds.\n";
	return 0;
}



















