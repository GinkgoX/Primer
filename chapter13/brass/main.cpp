#include<iostream>
#include"brass.h"

using namespace std;

int main()
{
	Brass worker("Mark lee", 324124, 4000.00);
	BrassPlus bussinessmen("Mating lee", 112112, 8000.00);
	
	worker.viewAcct();
	worker.deposit(1000.02);
	worker.withdraw(5000);
	worker.viewAcct();
	
	bussinessmen.viewAcct();
	bussinessmen.deposit(2000.0);
	bussinessmen.viewAcct();
	bussinessmen.withdraw(10300.00);
	bussinessmen.viewAcct();
	bussinessmen.withdraw(30.00);
	bussinessmen.viewAcct();
	return 0;
}


