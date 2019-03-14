#ifndef PERSION_H_
#define PERSION_H_

#include<iostream>
#include<string>

using std::string;

class Persion
{
private:
	string fname;
	string lname;
protected:
	virtual void data()const;
	virtual void get();
public:
	Persion():fname("Null"), lname("Null"){};
	Persion(const string &f, const string &l):fname(f), lname(l){};
	Persion(const Persion &p):fname(p.fname), lname(p.lname){};
	virtual ~Persion() = 0;
	virtual void set() = 0;
	virtual void show()const = 0;
};

class Gunslinger:virtual public Persion
{
private:
	int nicks;
protected:
	void data()const;
	void get();
public:
	Gunslinger():nicks(0), Persion(){};
	Gunslinger(int n, const string &f, const string &l):nicks(n), Persion(f, l){};
	Gunslinger(int n, const Persion &p):nicks(n), Persion(p){};
	void set();
	void show()const;
	double draw()const;
};

class PokerPlayer:virtual public Persion
{
protected:
	void data()const;
public:
	PokerPlayer():Persion(){};
	PokerPlayer(const string &f, const string &l):Persion(f, l){};
	PokerPlayer(const Persion &p):Persion(p){};
	void set(){Persion::set(); };
	void show()const;
	int draw()const;
};

class BadDude:public Gunslinger, public PokerPlayer
{
protected:
	void data()const;
	void get();
public:
	BadDude(){};
	BadDude(int n, const string &f, const string &l):Persion(f, l), Gunslinger(n, f, l), PokerPlayer(f, l){};
	BadDude(int n, const Persion &p):Persion(p), Gunslinger(n, p), PokerPlayer(p){};
	BadDude(const Gunslinger &g):Persion(g), Gunslinger(g), PokerPlayer(g){};
	BadDude(int n, const PokerPlayer &pk):Persion(pk), Gunslinger(n, pk), PokerPlayer(pk){};
	void set();
	void show()const;
	int cDraw()const;
	double gDraw()const;
};

#endif



