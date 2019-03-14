#include<iostream>
#include"worker.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Worker::Worker():name("Null"), id(0L)
{

}

Worker::Worker(const string &s, long n):name(s), id(n)
{

}

Worker::~Worker()
{

}

void Worker::get()
{
	getline(cin, name);
	cout << "Enter the worker's ID :" ;
	cin >> id;
	while(cin.get() != '\n')
	{
		continue;
	}
}

void Worker::data()const
{
	cout << "Name : " << name << endl;
	cout << "Employee ID : " << id << endl;
}


Waiter::Waiter():Worker(),panache(0)
{

}

Waiter::Waiter(const string &s, long n, int p):Worker(s, n),panache(p)
{

}

Waiter::Waiter(const Worker &wk, int p):Worker(wk), panache(p)
{

}

void Waiter::get()
{
	cout << "Enter waiter's panache : ";
	cin >> panache;
	while(cin.get() != '\n')
	{
		continue;
	}
}

void Waiter::set()
{
	cout << "Enter waiter's name : ";
	Worker::get();
	get();
}

void Waiter::show()const
{
	cout << "Category : waiter \n";
	Worker::data();
	data();
}

void Waiter::data()const
{
	cout << "Panache : " << panache << endl;
}

char* Singer::pv[Singer::Vtypes] = {(char*)"other", (char*)"alto", (char*)"contralto", (char*)"soprano", (char*)"bass", (char*)"baritone", (char*)"tenor"};


Singer::Singer():Worker(),voice(other)
{

}

Singer::Singer(const string &s, long n, int v):Worker(s, n), voice(v)
{

}

Singer::Singer(const Worker &wk, int v):Worker(wk), voice(v)
{

}

void Singer::get()
{
	int i;
	cout << "Enter singer's vocal range : \n";
	for(i = 0; i < Vtypes; i++)
	{
		cout << i << " : " << pv[i] << "	";
		if(i % 4 == 3)
		{
			cout << endl;
		}
	}
	if(i % 4 != 0)
	{
		cout << endl;
	}
	cin >> voice;
	while(cin.get() != '\n')
	{
		continue;
	}
}

void Singer::set()
{
	cout << "Enter singer name : " ;
	Worker::get();
	get();
}

void Singer::show()const
{
	cout << "Category : singer \n";
	Worker::data();
	data();
}

void Singer::data()const
{
	cout << "Vocal range : " << pv[voice] << endl;
}

SingingWaiter::SingingWaiter()
{

}

SingingWaiter::SingingWaiter(const string &sg, long n, int p, int v):Worker(sg, n), Waiter(sg, n, p), Singer(sg, n, v)
{

}

SingingWaiter::SingingWaiter(const Worker &wk, int p, int v):Worker(wk), Waiter(wk, p),Singer(wk, v)
{

}

SingingWaiter::SingingWaiter(const Waiter &wt, int v):Worker(wt), Waiter(wt),Singer(wt, v)
{

}

SingingWaiter::SingingWaiter(const Singer &sg, int p):Worker(sg), Waiter(sg, p),Singer(sg)
{

} 

void SingingWaiter::get()
{
	Waiter::get();
	Singer::get();
}

void SingingWaiter::set()
{
	cout << "Enter singingwaiter's name : ";
	Worker::get();
	get();
}

void SingingWaiter::show()const
{
	cout << "Category : singingwaiter :\n";
	Worker::data();
	data();
}

void SingingWaiter::data()const
{
	Singer::data();
	Waiter::data();
}

