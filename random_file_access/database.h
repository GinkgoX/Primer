#ifndef DATABASE_H_
#define DATABASE_H_

#include<iostream>
#include<fstream>

using namespace std;

template<class T>
class Database
{
private:
	fstream database;
	char fname[20];
	ostream & print(ostream &os);
	void add(T &t);
	bool find(const T &t);
	void modify(const T &t);
	friend ostream & operator<<(ostream &os, Database &d)
	{
		return d.print(os);
	}
public:
	Database();
	void run();
};

#endif

