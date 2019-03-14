#include<iostream>
#include"brass.h"

const int CLIENTS = 4;
const int LEN = 40;

using namespace std;

int main()
{
	Brass *p_client[CLIENTS];
	for(int i = 0; i < CLIENTS; i++)
	{
		char name[LEN];
		long num;
		double bal;
		char type;
		cout << "Enter client name : ";
		cin.getline(name, LEN);
		cout << "Enter client account number : ";
		cin >> num;
		cout << "Enter opening balance : ";
		cin >> bal;
		cout << "Enter 1 for Brass Account Or 2 for BrassPlus Account : ";
		while((cin >> type) && (type != '1' ) && (type != '2'))
		{
			cout << "Enter either 1 Or 2 :";
		}
		if(type == '1')
		{
			p_client[i] = new Brass(name, num, bal);
		}
		else
		{
			double ml,rt;
			cout << "Enter the overdraft limit: ";
			cin >> ml;
			cout << "Enter the interest rate : ";
			cin >> rt;
			p_client[i] = new BrassPlus(name, num, bal, ml, rt);
		}
		while(cin.get() != '\n')
		{
			continue;
		}
	}
	cout << endl;
	for(int i = 0; i < CLIENTS; i++)
	{
		p_client[i]->viewAcct();
	}
	for(int i = 0; i < CLIENTS; i++)
	{
		delete p_client[i];
	}
	
	return 0;
}


