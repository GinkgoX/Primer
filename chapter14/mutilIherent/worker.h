#ifndef WORKER_H_
#define WORKER_H_
#include<string>

class Worker
{
private:
	std::string name;
	long id;
protected:
	virtual void data()const;
	virtual void get();
public:
	Worker();
	Worker(const std::string &s, long n);
	virtual ~Worker() = 0;
	virtual void set() = 0;
	virtual void show() const = 0;
};

class Waiter:virtual public Worker
{
private:
	int panache;
protected:
	void data()const;
	void get();
public:
	Waiter();
	Waiter(const std::string &s, long n, int p = 0);
	Waiter(const Worker &wk, int p = 0);
	void set();
	void show()const;
};

class Singer:virtual public Worker
{
protected:
	enum{other, alto, contralto, soprano, bass, baritone, tenor};
	enum{Vtypes = 7};
	void data()const;
	void get();	
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer();
	Singer(const std::string &s, long n, int v = other);
	Singer(const Worker &wk, int v = other);
	void set();
	void show()const;
};

class SingingWaiter:public Singer, public Waiter
{
protected:
	void data()const;
	void get();
public:
	SingingWaiter();
	SingingWaiter(const std::string &s, long n, int p, int v);
	SingingWaiter(const Worker &wk, int p, int v);
	SingingWaiter(const Waiter &wt, int v);
	SingingWaiter(const Singer &sg, int p);
	void set();
	void show()const;
};

#endif
