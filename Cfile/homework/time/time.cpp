#include<iostream>
#include"time.h"

Time::Time()
{
	hour = 0;
	min = 0;
}

Time::Time(int h, int m)
{
	hour = h;
	min = m;
}
Time::~Time()
{

}

void Time::addHr(int h)
{
	hour += h;
}

void Time::addMin(int m)
{
	min += m;
	hour += min / 60;
	min = min % 60;
}

void Time::reset(int h, int m)
{
	hour = h;
	min = m;
}

Time Time::operator+(const Time &t)const
{
	Time s;
	s.min = min + t.min;
	s.hour = hour + t.hour + s.min / 60;
	s.min = s.min % 60;
	return s;
}

Time Time::operator-(const Time &t)const
{
	Time s; 
	int total1, total2;
	total1 = t.min + 60*t.hour;
	total2 = min + 60*hour;
	s.hour = (total2 - total1) / 60;
	s.min = (total2 - total1) % 60;
	return s;
}

Time Time::operator*(double n)const
{
	Time s;
	long total = 60*hour*n + min*n;
	s.hour = total / 60;
	s.min = total % 60;
	return s;
}

std::ostream & operator<<(std::ostream &os, const Time &t)
{
	os << "Time is : " << t.hour << " : " << t.min;
	return os; 
}



