#include<ctime>
#include<iostream>
#include<cstdlib>
#include<typeinfo>

using namespace std;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0):hold(h){};
	virtual void speak()const{cout << "I am a grand class . " << endl;};
	virtual int value()const{return hold;};
};

class Superb:public Grand
{
public:
	Superb(int h = 0):Grand(h){};
	void speak()const{cout << "I am a superb class . " << endl;};
	virtual void say()const{cout << "I hold a value of " << value() << endl;};
};

class Magnificent:public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, int c = 'A'):Superb(h), ch(c){};
	void speak()const{cout << "I am a magnificent class . " << endl;};
	void say()const{cout << "I have the character " << ch << " and I hold value of " << value() << endl;};
};

Grand *getOne();

int main()
{
	srand(time(0));
	Grand *pg;
	Superb *ps;
	for(int i = 0; i < 5; i++)
	{
		pg = getOne();
		cout << "Now, processing type " << typeid(*pg).name() << endl;
		pg->speak();
		if(ps = dynamic_cast<Superb *>(pg))
		{
			ps->say();
		}
		if(typeid(Magnificent) == typeid(*pg))
		{
			cout << "Yes, you are really a magnificent class . " << endl;
		}
	}
	return 0;
}

Grand *getOne()
{
	Grand *p;
	switch(rand() % 3)
	{
		case 0:
				p = new Grand(rand() % 100);
				break;
		case 1:
				p = new Superb(rand() % 100);
				break;
		case 2:
				p = new Magnificent(rand() % 100, 'A' + rand() % 26);
				break;
	}
	return p;
}

