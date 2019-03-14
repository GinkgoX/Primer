#include<iostream>
#include"stone.h"

Stone::Stone()
{
	stone = pounds = pds_left = 0;
}

Stone::Stone(double lbs)
{
	stone = int(lbs) / pps;
	pounds = lbs;
	pds_left = int(lbs) % pps + lbs - int(lbs);
}

Stone::Stone(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stone * pps + lbs;
}

Stone::~Stone()
{

}

void Stone::show_lbs()const
{
	std::cout << "Stone = " << stone << "stones, " << pds_left << " pounds .\n"; 
}

void Stone::show_stn()const
{
	std::cout << "Stone = " << pounds << " pounds .\n";
}

Stone::operator int()const
{
	return int(pounds + 0.5);
}

Stone::operator double()const
{
	return pounds;
}


