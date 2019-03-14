#include<iostream>
#include<cstring>
#include"worker.h"

using namespace std;

const int SIZE = 5;

int main()
{
	Worker *wk[SIZE];
	cout << "Hint w: waiter, s: singer, t: singingwaiter , q : quit \n";
	for(int i = 0; i < SIZE; i++)
	{
		char choice;
		cout << "Enter employee catelogy : ";
		cin >> choice;
		switch(choice)
		{
			case('w'):
				wk[i] = new Waiter;
				break;
			case('s'):
				wk[i] = new Singer;
				break;
			case('t'):
				wk[i] = new SingingWaiter;
				break;
			case('q'):
				break;
			default:
				cout << "ONlY w, s, t, q avaiable ! , try again : ";
				cin >> choice;
		}
		cin.get();
		wk[i]->set();
	}
	
	cout << "Here is your staff : \n";
	for(int i = 0; i < SIZE; i++)
	{
		cout << endl;
		wk[i]->show();
	}
	
	for(int i = 0; i < SIZE; i++)
	{
		delete wk[i];
	}
	cout << "done . " << endl;
	return 0;
}



