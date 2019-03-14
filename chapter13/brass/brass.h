#ifndef BRASS_H_
#define BRASS_H_

class Brass
{
private:
	enum{MAX = 35};
	char fullname[MAX];
	long acctNum;
	double balance;
public:
	Brass(const char *c = "NullName", long an = -1, double bal = 0.0);
	void deposit(double amt);
	double viewBal()const;
	virtual void withdraw(double amt);
	virtual void viewAcct()const;
	virtual ~Brass();
};


class BrassPlus:public Brass
{
private:
	double maxLoad;
	double rate;
	double owesBank;
public:
	BrassPlus(const char *c = "NullName", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass &b, double ml, double r);
	void resetMax(double ml){maxLoad = ml;};
	void resetRate(double r){rate = r;};
	void resetOwes(double ows){owesBank = ows;};
	virtual void withdraw(double amt);
	virtual void viewAcct()const;
};
#endif

