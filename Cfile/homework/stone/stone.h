#ifndef STONE_H_
#define STONE_H_

class Stone
{
private:
	enum{pps = 14};
	int stone;
	double pounds;
	double pds_left;	
public:
	Stone();
	Stone(double lbs);
	Stone(int stn, double lbs);
	~Stone();
	void show_lbs()const;
	void show_stn()const;
	operator int()const;
	operator double()const;
};
#endif

