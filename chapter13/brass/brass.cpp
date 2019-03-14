#include<iostream>
#include<cstring>
#include"brass.h"

using std::cout;
using std::endl;
using std::ios_base;

Brass::Brass(const char *c, long an, double bal)
{
	strncpy(fullname, c, MAX - 1);
	fullname[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void Brass::deposit(double amt)
{
	if(amt < 0)
	{
		cout << "Negative deposit is not allowed, deposit cancelled !" << endl;
	}
	else
	{
		balance += amt; 
	}
}

double Brass::viewBal()const
{
	return balance;
}

void Brass::withdraw(double amt)
{
	if(amt < 0)
	{
		cout << "Negative withdraw is not allowed, withdraw cancelled !" << endl;
	}
	if(amt > balance)
	{
		cout << "amount shoud be less than your balance, withdraw cancelled ! " << endl;
	}
	else
	{
		balance -= amt;
	}
}

void Brass::viewAcct()const
{
	ios_base::fmtflags initalStage = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "------Info------" << endl;
	cout << "Client : " << fullname << endl;
	cout << "Accuont Number: " << acctNum << endl;
	cout << "Balance : " << balance << endl;
	cout.setf(initalStage);
}

Brass::~Brass()
{

}

BrassPlus::BrassPlus(const char *c, long an, double bal, double ml, double r):Brass(c, an, bal)
{
	maxLoad = ml;
	rate = r;
	owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &b, double ml, double r):Brass(b)
{
	maxLoad = ml;
	rate = r;
	owesBank = 0.0;
}

void BrassPlus::withdraw(double amt)
{
	ios_base::fmtflags initalStage = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	double bal = viewBal();
	if(amt < 0)
	{
		cout << "Negative withdraw is not allowed, withdraw cancelled !" << endl;
	}
	else if(amt < bal)
	{
		Brass::withdraw(amt);
	}
	else if(amt < bal + maxLoad - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1 + rate);
		cout << "Bank Advance : " << advance << endl;
		cout << "Finance Charge : " << advance * rate << endl;
		deposit(advance);
		Brass::withdraw(amt);
	}
	else
	{
		cout << "Withdraw overtakes the limited amount, withdraw cancelled !" << endl;
	}
	cout.setf(initalStage);
}

void BrassPlus::viewAcct()const
{
	ios_base::fmtflags initalStage = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	Brass::viewAcct();
	cout << "MaxLoad : " << maxLoad << endl;
	cout << "Rate : " << rate << endl;
	cout << "OewsBank : " << owesBank << endl;
	cout.setf(initalStage);
}

