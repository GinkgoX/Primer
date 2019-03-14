#ifndef WINEC_H_
#define WINEC_H_

#include<iostream>
#include<valarray>
#include<string>

using std::string;
using std::valarray;
using std::cout;
using std::endl;

template<class Y, class B>
class Pair
{
private:
	Y year;
	B bottle;
public:
	Pair(){};
	Pair(const Y &y, const B &b):year(y), bottle(b){};
	~Pair(){};
	int sumPair()const;
	void showPair(int n)const;
	void setPair(const Y &y, const B &b);
};

template<class Y, class B>
int Pair<Y, B>::sumPair()const
{
	return bottle.sum();
}

template<class Y, class B>
void Pair<Y, B>::showPair(int n)const
{
	for(int i = 0; i < n; i++)
	{
		cout << "	" << year[i] << "	" << bottle[i] << endl;
	}
}

template<class Y, class B>
void Pair<Y, B>::setPair(const Y &y, const B &b)
{
	year = y;
	bottle = b;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine:private PairArray, private string
{
private:
	int yrs;
public:
	Wine(){};
	Wine(const char *l, int y, const int yr[], const int bot[]);
	Wine(const char *l, int y);
	~Wine(){};
	void getBottles();
	string & label();
	int sum()const;
	void show()const;
	
};

#endif

