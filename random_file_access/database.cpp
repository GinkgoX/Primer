#include<iostream>
#include<fstream>
#include"personal.h"
#include"student.h"
#include"database.h"

using namespace std;

template<class T>
Database<T>::Database()
{
	
}

template<class T>
void Database<T>::add(T &t)
{
	database.open(fname, ios::in | ios::out | ios::binary);
	database.seekp(0, ios::end);
	t.writeToFile(database);
	database.close();
}

template<class T>
bool Database<T>::find(const T &t)
{
	T temp;
	database.open(fname, ios::in | ios::binary);
	while(!database.eof())
	{
		temp.readFromFile(database);
		if(temp == t)
		{
			database.close();
			return true;
		}
	}
	database.close();
	return false;
}

template<class T>
void Database<T>::modify(const T &t)
{
	T temp;
	database.open(fname, ios::in | ios::out | ios::binary);
	while(!database.eof())
	{
		temp.readFromFile(database);
		if(temp == t)
		{
			cin >> temp;
			database.seekp(-t.size(), ios::cur);
			temp.writeToFile(database);
			database.close();
			return;
		}
	}
	database.close();
	cout << "The record to be modify does exit in the database . ";
}

template<class T>
ostream & Database<T>::print(ostream &os)
{
	T temp;
	database.open(fname, ios::in | ios::binary);
	while(true)
	{
		temp.readFromFile(database);
		if(database.eof())
		{
			break;
		}
		os << temp << endl;
	}
	database.close();
	return os;
}

template<class T>
void Database<T>::run()
{
	cout << "File name : ";
	cin >> fname;
	char select;
	T rec;
	cout << " 1) 	A(add)	2) 	F(find)	3) 	M(modify) 	4) E(exit)" << endl;
	cout << "Enter your option : ";
	while(select = cin.get() != 'E')
	{
		cin.get();
		switch(select)
		{
			case 'A':
			case 'a':
					cin >> rec;
					add(rec);
					break;
			case 'F':
			case 'f':
					rec.readKey();
					if(!find(rec))
					{
						cout << "The database does not exit the record . " << endl;
					}
					break;
			case 'M':
			case 'm':
					rec.readKey();
					modify(rec);
					break;
			default:
					cout << "Wrong option , please try again ! " << endl;
		}
		cout << "Enter your option again : ";
	}
}

