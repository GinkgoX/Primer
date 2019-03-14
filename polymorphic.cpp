#include<iostream>

using namespace std;

class Class1
{
public:
	virtual void f()
	{
		cout << "Function f() in Class1 . " << endl;
	}
	void g()
	{
		cout << "Function g() in Class1 . " << endl;
	}
};

class Class2
{
public:
	virtual void f()
	{
		cout << "Function f() in Class2 . " << endl;
	}
	void g()
	{
		cout << "Function g() in Class2 . " << endl;
	}
};

class Class3
{
public:
	virtual void h()
	{
		cout << "Function h() in Class3 . " << endl;
	}
};

int main()
{
	Class1 object1, *p;
	Class2 object2;
	Class3 object3;
	
	p = &object1;
	p->f();
	p->g();
	
	p = (Class1 *) &object2;
	p->f();
	p->g();
	
	p = (Class1 *) &object3;
	// p->f(); # Wroning : Class1 has no member named f, but Class3 has the virtual h()
	p->g();
	// p->h(); # Error : Class1 has no member named h
	
	return 0;
}
