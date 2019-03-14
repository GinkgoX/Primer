#ifndef SALES_H_
#define SALES_H_

#include<stdexcept>
#include<cstring>

class Sales
{
public:
	enum{MONTH = 12};
private:
	int year;
	double gross[MONTH];
public:

	class bad_index:public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix, const char *s = "Index Error in Sales object . \n");
		int bi_val()const{return bi;};
	};
	
	explicit Sales(int y = 0);
	Sales(int y, const double *gr, int n);
	virtual ~Sales(){};
	int year_val()const{return year;};
	virtual double operator[](int i)const throw(std::logic_error);
	virtual double & operator[](int i) throw(std::logic_error);
};

class LabelSales:public Sales
{
public:
	static const int STRLEN = 50;
private:
	char label[STRLEN];
public:

	class nbad_index:public Sales::bad_index
	{
	private:
		char lbl[STRLEN];
	public:
		nbad_index(const char *lb, int ix, const char *s = "Index error in LabelSales object . \n");
		const char *lbl_val(){return lbl;};
	};
	
	explicit LabelSales(int y = 0, const char *s = "none");
	LabelSales(int y, const double *gr, int n, const char *lb);
	virtual ~LabelSales(){};
	const char *label_val()const{return label;};
	virtual double operator[](int i)const throw(std::logic_error);
	virtual double & operator[](int i) throw(std::logic_error);
};

#endif

