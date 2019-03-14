#ifndef ACCTABC_H_H
#define ACCTABC_H_H

class AcctABC
{
private:
	enum{MAX = 35};
	char fullname[MAX];
	long acctNum;
	double balance;
protected:
	const char *showName()const{return fullname;};
	long showAcctNum()const{return acctNum;};
	std::ios_base::fmtflags setFormat()const;
public:
	AcctABC(const char *c = "NullName", long an = -1, double bal = 0.0);
	void deposit(double amt);
	double viewBal()const{return balance;};
	virtual void withdraw(double amt) = 0;
	virtual void viewAcct()const = 0;
	virtual ~AcctABC(){}
};

class Brass:public AcctABC
{
public:
	Brass(const char *c = "NullName", long an = -1, double bal = 0.0);
	virtual void withdraw(double amt);
	virtual void viewAcct()const;
	virtual ~Brass(){}
};

class BrassPlus:public AcctABC
{
private:
	double maxLoad;
	double rate;
	double owesBank;
public:
	BrassPlus(const char *c = "NullName", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass &b, double ml = 500, double r = 0.10);
	void resetMaxload(double ml){maxLoad = ml; };
	void resetRate(double r){rate = r; };
	void resetOwes(double ows){owesBank = ows;};
	virtual void withdraw(double amt);
	virtual void viewAcct()const;
};
#endif

