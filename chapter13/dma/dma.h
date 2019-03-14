#ifndef DMA_H_
#define DMA_H_

#include<iostream>

class baseDMA
{
private:
	char *label;
	int rate;
public:
	baseDMA(const char *lb = "null", int r = 0);
	baseDMA(const baseDMA &b);
	virtual ~baseDMA();
	const char *showLabel()const{return label;};
	int showRate()const{return rate;};
	baseDMA & operator=(const baseDMA &b);
	virtual void show()const;
	friend std::ostream & operator<<(std::ostream &os, const baseDMA &b);
};

class lacksDMA:public baseDMA
{
private:
	enum{COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char *co = "black", const char *lb = "null", int r = 0);
	lacksDMA(const char *co, const baseDMA &bd);
	const char *showColor()const{return color;};
	virtual void show()const;
	friend std::ostream & operator<<(std::ostream &os, const lacksDMA &ld);
};

class hasDMA:public baseDMA
{
private:
	char *style;
public:
	hasDMA(const char *st = "none", const char *lb = "null", int r = 0);
	hasDMA(const char *st, const baseDMA &bd);
	hasDMA(const hasDMA &hd);
	~hasDMA();
	const char *showStyle()const{return style;};
	hasDMA & operator=(const hasDMA &hd);
	virtual void show()const;
	friend std::ostream & operator<<(std::ostream &os, const hasDMA &hd);
};

#endif
