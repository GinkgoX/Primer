#include<iostream>
#include"queuetp.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void Worker::set()
{
	cout << "Enter worker's name : ";
	getline(cin, name);
	cout << "Enter worker's ID : ";
	cin >> id;
	while(cin.get() != '\n')
	{
		continue;
	}
}

void Worker::show()const
{
	cout << "Name : " << name << "	" << "ID : " << id << endl;
}

