#include<iostream>
#include<cstring>
#include"stack.h"

using namespace std;

int main()
{
	Stack st;
	Item *it = new Item[11];
	
	it[0] = 1;
	it[1] = 1;
	for(int i = 2; i < 11; i++)
	{
		it[i] = it[i-1] + it[i-2];
	}
	
	for(int i = 0; i < 11; i++)
	{
		cout << it[i] << " ";
	}
	cout << endl;
	
	for(int i = 0 ; i < 11; i++)
	{
		st.push(it[i]);
	} 
	cout << st << endl;
	
	cout << "-----Stack(const Stack &st)-----" << endl;
	Stack st1(st);
	cout << st1 << endl;
	for(int i = 0; i < 11; i++)
	{
		st1.pop(it[i]);
	}
	
	for(int i = 0; i < 11; i++)
	{
		cout << it[i] << " ";
	}
	
	cout << endl;
	
	cout << "-----Stack & operator=(const Stack &st)-----" << endl;
	Stack st2 = st;
	cout << st2 << endl;

	delete[] it;	
	return 0;
}







