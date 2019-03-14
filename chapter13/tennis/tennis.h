#ifndef TENNIS_H_
#define TENNIS_H_

class TableTennisPlayer
{
private:
	enum{LIM = 20};
	char fname[LIM];
	char lname[LIM];
	bool hTable;
public:
	TableTennisPlayer(const char *fn = "none", const char *ln = "none", bool ht = false);
	TableTennisPlayer(const TableTennisPlayer &tp);
	void name()const;
	bool hasTable()const{return hTable;};
	void resetTable(bool b){hTable = b;};
};

class RatePlayer:public TableTennisPlayer
{
private:
	unsigned int rate;
public:
	RatePlayer(unsigned int r, const char *fn = "none", const char *ln = "none", bool ht = false);
	RatePlayer(unsigned int r, const TableTennisPlayer &tp);
	unsigned int rating(){return rate;};
	void resetRating(unsigned int rst){rate = rst;};
};

#endif


