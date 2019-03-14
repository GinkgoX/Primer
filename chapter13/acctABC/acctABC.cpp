#include<iostream>
#include<cstring>
#include"acctABC.h"

using std::cout;
using std::endl;
using std::ios_base;

ios_base::fmtflags AcctABC::setFormat()const
{
	ios_base::fmtflags initalState = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2); 
	return initalState;
}

AcctABC::AcctABC(const char *c, long an, double bal)
{
	strncpy(fullname, c, MAX - 1);
	fullname[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void AcctABC::deposit(double amt)
{
	if(amt < 0)
	{
		cout << "Negative deposit is not allowed, deposit cancelled ! " << endl;
	}
	else
	{
		balance += amt;
	}
}

void AcctABC::withdraw(double amt)
{
	balance -= amt;
}

Brass::Brass(const char *c, long an, double bal):AcctABC(c, an, bal)
{

}

void Brass::withdraw(double amt)
{
	if(amt < 0)
	{
		cout << "Negative withdraw is not allowed, withdraw cannelled ! " << endl;
	}
	else if(amt < viewBal())
	{
		AcctABC::withdraw(amt);
	}
	else
	{
		cout << "withdraw overtakes the balance, withdraw cannelled !" << endl;
	}
}

void Brass::viewAcct()const
{
	cout << "-----Brass Information-----" << endl;
	ios_base::fmtflags initalState = setFormat();
	cout << "Brass Client : " << showName() << endl;
	cout << "Account Number : " << showAcctNum() << endl;
	cout << "Account Balance : " << viewBal()<< endl;
	cout.setf(initalState);
}

BrassPlus::BrassPlus(const char *c, long an, double bal, double ml, double r):AcctABC(c, an, bal)
{
	maxLoad = ml;
	rate = r;
	owesBank = 0;
}

BrassPlus::BrassPlus(const Brass &b, double ml, double r):AcctABC(b)
{
	maxLoad =ml;
	rate = r;
	owesBank = 0;
}

void BrassPlus::viewAcct()const
{
	cout << "-----BrassPlus Information-----" << endl;
	ios_base::fmtflags initalState = setFormat();
	cout << "BrassPlus Client : " << showName() << endl;
	cout << "Account Number : " << showAcctNum() << endl;
	cout << "Account Balance : " << viewBal() << endl;
	cout << "Maxmum Load : " << maxLoad << endl;
	cout << "Owes Bank : " << owesBank << endl;
	cout << "Load rate : " << 100 * rate << "%" << endl;
	cout.setf(initalState);
}

void BrassPlus::withdraw(double amt)
{
	ios_base::fmtflags initalState = setFormat();
	double bal = viewBal();
	if(amt < 0)
	{
		cout << "Negative withdraw is not allowed, withdraw cancelled !" << endl;
	}
	else if(amt < bal)
	{
		AcctABC::withdraw(amt);
	}
	else if(amt < bal + maxLoad - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance *(1 + rate);
		cout << "Bank Advace : " << advance << endl;
		cout << "Finance charge : " << advance * rate << endl;
		deposit(advance);
		AcctABC::withdraw(amt);
		
	}
	else
	{
		cout << "withdraw overtakes the limited amount, withdraw cancelled !" << endl;
	}
	cout.setf(initalState);
}







