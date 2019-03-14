#ifndef TIME_H_
#define TIME_H_

#include<iostream>

class Time
{
private:
	int hour;
	int min;
public:
	Time();
	Time(int h, int m = 0);
	~Time();
	void addHr(int h);
	void addMin(int m);
	void reset(int h = 0, int m = 0);
	Time operator+(const Time &t)const;
	Time operator-(const Time &t)const;
	Time operator*(double n)const;
	
	friend Time operator*(double n, const Time &t)		//inline function
	{
		return t*n;
	}			
	
	friend std::ostream & operator<<(std::ostream &os, const Time &t);
	
};
#endif







