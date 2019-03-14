#ifndef WINE_H_
#define WINE_H_

#include<iostream>
#include<valarray>
#include<string>

template<class Y, class B>
class Pair
{
private:
	Y year;
	B bottle;
public:
	Pair(){};
	Pair(const Y &y, const B &b):year(y), bottle(b){};
	int sumPair()const;
	void setPair(const Y &y, const B &b);
	void showPair(int n)const;
};

template<class Y, class B>
int Pair<Y, B>::sumPair()const
{
	return bottle.sum();
}

template<class Y, class B>
void Pair<Y, B>::setPair(const Y &y, const B &b)
{
	year = y;
	bottle = b;
}

template<class Y, class B>
void Pair<Y, B>::showPair(int n)const
{
	for(int i = 0; i < n; i++)
	{
		std::cout << "	" << year[i] << "	" << bottle[i] << std::endl;
	}
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string name;
	PairArray yb;
	int yrs;
public:
	Wine(){};
	Wine(const char *l, int y, const int yr[], const int bot[]);
	Wine(const char *l, int y);
	~Wine(){};
	void getBottles();
	int sum()const;
	std::string & label();
	void show()const;
};
#endif
