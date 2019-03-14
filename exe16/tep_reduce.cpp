#include<iostream>
#include<ctime>
#include<string>
#include<list>
#include<iterator>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int LIM = 10;
const int SLIM = 5;

template<class T>
void show(T a[], int n);

template<class T>
int reduce(T a[], int n);

int main()
{
	srand(time(0));
	long ldata[LIM];
	string sdata[5] = {"C++", "c++", "c++", "C++", "g++"};
	for(int i = 0; i < LIM; i++)
	{
		ldata[i] = rand() % 5;
	}
	cout << "# Original long data #" << endl;
	show(ldata, LIM);
	show(sdata, SLIM);
	cout << "# After reduce long date #" << endl;
	cout << "long data contains " << reduce(ldata, LIM) << " different values " << endl;
	cout << "string data contains "<< reduce(sdata, SLIM) << " different strings " << endl;
	
	cout << "done . " << endl;
	return 0;
}

template<class T>
void show(T a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


template<class T>
int reduce(T a[], int n)
{
	list<T> lt;
	for(int i = 0; i < n; ++i)
	{
		lt.push_back(a[i]);
	}
	lt.sort();
	lt.unique();
	typename list<T>::iterator li;
	for(li = lt.begin(); li != lt.end(); ++li)
	{
		cout << *li << " ";
	}
	cout << endl;
	return lt.size();
}

