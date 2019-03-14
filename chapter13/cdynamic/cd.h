#ifndef CD_H_
#define CD_H_

class Cd
{
private:
	char *performers;
	char *label;
	int selections;
	double playertime;
public:
	Cd();
	Cd(const char *pf, const char *lb, int sl, double pt);
	Cd(const Cd &cd);
	virtual ~Cd();
	virtual void report()const;
	Cd & operator=(const Cd &cd);
};

class Classic:public Cd
{
private:
	char *works;
public:
	Classic();
	Classic(const char *wk, const char *pf, const char *lb, int sl, double pt);
	Classic(const Classic &cs);
	~Classic();
	virtual void report()const;
	Classic & operator=(const Classic &cs);
};

#endif

