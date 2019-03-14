#include<cstring>
#include"dma.h"

using std::cout;
using std::endl;
using std::strcpy;
using std::strncpy;
using std::strlen;
using std::ostream;

baseDMA::baseDMA(const char *lb, int r)
{
	label = new char[strlen(lb) + 1];
	strcpy(label, lb);
	rate = r;
}

baseDMA::baseDMA(const baseDMA &bd)
{
	label = new char[strlen(bd.label) + 1];
	strcpy(label, bd.label);
	rate = bd.rate;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA &bd)
{
	if(this == &bd)
	{
		return *this;
	}
	delete[] label;
	label = new char[strlen(bd.label) + 1];
	strcpy(label, bd.label);
	rate = bd.rate;
	return *this; 
} 

void baseDMA::show()const
{
	cout << "Label : " << showLabel() << endl;
	cout << "Rate : " << showRate() << endl;
}

ostream & operator<<(ostream &os, const baseDMA &bd)
{
	os << "Label : " << bd.label << endl;
	os << "Rate : " << bd.rate << endl;
	return os;
}

lacksDMA::lacksDMA(const char *co, const char *lb, int r):baseDMA(lb, r)
{
	strncpy(color, co, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char *co, const baseDMA &bd):baseDMA(bd)
{
	strncpy(color, co, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::show()const
{
	cout << "Label : " << showLabel() << endl;
	cout << "Rate : " << showRate() << endl;
	cout << "Color : " << showColor() << endl;
}

ostream & operator<<(ostream &os, const lacksDMA &ld)
{
	os << (const baseDMA &)ld;
	os << "Color : " << ld.color << endl;
	return os;
}

hasDMA::hasDMA(const char *st, const char *lb, int r):baseDMA(lb, r)
{
	style = new char[strlen(st) + 1];
	strcpy(style, st);
}

hasDMA::hasDMA(const char *st, const baseDMA &bd):baseDMA(bd)
{
	style = new char[strlen(st) + 1];
	strcpy(style, st);
}

hasDMA::hasDMA(const hasDMA &hd):baseDMA(hd)
{
	style = new char[strlen(hd.style) + 1];
	strcpy(style, hd.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA &hd)
{
	if(this == &hd)
	{
		return *this;
	}
	baseDMA::operator=(hd);
	style = new char[strlen(hd.style) + 1];
	strcpy(style, hd.style);
	return *this;
}

void hasDMA::show()const
{
	cout << "Label : " << showLabel() << endl;
	cout << "Rate : " << showRate() << endl;
	cout << "Style : " << showStyle() << endl;
}

ostream & operator<<(ostream &os, const hasDMA &hd)
{
	os << (const baseDMA &)hd;
	os << "Style : " << hd.style << endl;
	return os;
}

