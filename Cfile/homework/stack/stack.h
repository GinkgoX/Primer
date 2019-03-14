#include<iostream>

using std::ostream;
using std::istream;

typedef unsigned long Item;

#ifndef STACK_H_
#define STACK_H_
class Stack
{
private:
	enum{MAX = 10};
	Item *pitems;
	int size;
	int top;
public:
	Stack(int n = 10);
	Stack(const Stack &st);
	~Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item &it);
	bool pop(Item &it);
	Stack & operator=(const Stack &st);
	friend ostream & operator<<(ostream &os, const Stack &st);
};
#endif

