#include<iostream>
#include<cstring>
#include"stack.h"

using namespace std;

Stack::Stack(int n)
{
	if(n > MAX)
	{
		cout << "The maxmum numbers of this stack is " << MAX ;
		cout << " and we will set as default n = " << MAX << endl;
		n = MAX;
	}
	pitems = new Item[n];
	size = 0;
	top = 0;
}

Stack::Stack(const Stack &st)
{
	pitems = new Item[st.size];
	top = 0;
	size = 0;
	for(int i = 0; i < st.size; i++)
	{
		pitems[i] = st.pitems[i];
		top++;
		size++;
	}
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::isempty()const
{
	return top == 0;
}

bool Stack::isfull()const
{
	return top == MAX;
}

bool Stack::push(const Item &it)
{
	if(isfull())
	{
		cout << "THe stack is alread full !" << endl;
		return false;
	}
	pitems[top++] = it;
	size++;
	return true;
}

bool Stack::pop(Item &it)
{
	if(isempty())
	{
		cout << "The stack is alread empty !" << endl;
		return false;
	}
	it = pitems[--top];
	size--;
	return true;
}

Stack & Stack::operator=(const Stack &st)
{
	delete[] pitems;
	pitems = new Item[st.size];
	size = 0;
	top = 0;
	for(int i = 0; i < st.size; i++)
	{
		pitems[i] = st.pitems[i];
		size++;
		top++;
	}	
	return *this;
}

ostream & operator<<(ostream &os, const Stack &st)
{
	for(int i = 0; i < st.top; i++)
	{
		os << st.pitems[i] << " ";
	}
	return os;
}

