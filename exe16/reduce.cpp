#include<iostream>
#include<list>
#include<ctime>
#include<cstdlib>

using namespace std;

const int LIM = 10;
void show(long a[], int n = LIM);
int reduce(long ar[], int n);


int main()
{
	srand(time(0));
	long data[LIM];
	long temp;
	for(int i = 0; i < LIM; i++)
	{
		data[i] = rand() % 5;
	}
	cout << "# Original data #" << endl;
	show(data, LIM);	
	cout << "# After reduce data #" <<endl;
	cout << "The data contains " << reduce(data, LIM) << " different values. " << endl;
	
	cout << "done . " << endl;
	return 0;
}

void show(long a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int reduce(long a[], int n)
{
	list<long> ll;
	for(int i = 0; i < n; i++)
	{
		ll.push_back(a[i]);
	}
	ll.sort();
	ll.unique();
	list<long>::iterator li;
	for(li = ll.begin(); li != ll.end(); ++li)
	{
		cout << *li << " ";
	}
	cout << endl;
	return ll.size();
}
