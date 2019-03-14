#include"sales.h"

Sales::bad_index::bad_index(int y, const char *s):bi(y), std::logic_error(s)
{

}

Sales::Sales(int y)
{
	year = y; 
	for(int i = 0; i < MONTH; i++)
	{
		gross[i] = 0;
	}
}

Sales::Sales(int y, const double *gr, int n)
{
	year = y;
	int lim = (n < MONTH) ? n : MONTH;
	int i;
	for(i = 0; i < lim; i++)
	{
		gross[i] = gr[i];
	}
	for(; i < MONTH; i++)
	{
		gross[i] = 0;
	}
}

double Sales::operator[](int i)const throw(std::logic_error)
{
	if(i < 0 || i >= MONTH)
	{
		throw bad_index(i);
	}
	return gross[i];
}

double & Sales::operator[](int i) throw(std::logic_error)
{
	if(i < 0 || i >= MONTH)
	{
		throw bad_index(i);
	}
	return gross[i];
}

LabelSales::nbad_index::nbad_index(const char *lb, int ix, const char *s):Sales::bad_index(ix, s)
{
	std::strcpy(lbl, lb);
}

LabelSales::LabelSales(int y, const char *s):Sales(y)
{
	std::strcpy(label, s);
}

LabelSales::LabelSales(int y, const double *gr, int n, const char *s):Sales(y, gr, n)
{
	std::strcpy(label, s);
}

double LabelSales::operator[](int i)const throw(std::logic_error)
{
	if(i < 0 || i >= MONTH)
	{
		throw nbad_index(label_val(), i);
	}
	return Sales::operator[](i);
}

double & LabelSales::operator[](int i) throw(std::logic_error)
{
	if(i < 0 || i >= MONTH)
	{
		throw nbad_index(label_val(), i);
	}
	return Sales::operator[](i);
}

