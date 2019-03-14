#include<iostream>
#include<string>
#include"queuetp.h"

using namespace std;

const int SIZE = 5;

int main()
{
	QueueTp<Worker *> wk(SIZE);
	Worker *temp;
	for(int i = 0; i < SIZE; i++)
	{
		char ch;
		cout << "Enter E(enqueue), D(dequeue), or Q(quit) : ";
		cin >> ch;
		if((ch == 'Q') || (ch == 'q'))
		{
			break;
		}
		switch(ch)
		{
			case 'E':
			case 'e':
						cin.get();
						temp = new Worker;
						temp->set();
						if(wk.isfull())
						{
							cout << "Queue is already full ! " << endl;
						}
						else
						{
							wk.enqueue(temp);
							cout << "Enqueue successfiily !" << endl;
						}
						break;
			case 'D':
			case 'd':
						if(wk.isempty())
						{
							cout << "Queue is already empty ! " << endl;
						}
						else
						{
							wk.dequeue(temp);
							cout << "Dequue successfiily !" << endl;
						}
						break;
			default:
						cout << "Only E(enqueue), D(dequeue), Q(quit) avaible, Please try again !" << endl;
		}
	}
	cout << "The queue counts :"  << wk.queueCount() << " items" << endl;
	cout << "The queue info as follows : " << endl;
	while(!wk.isempty())
	{
		wk.dequeue(temp);
		temp->show();
	}
	delete temp;
	cout << "done . " << endl;
	return 0;
}
