#include<iostream>
#include<cstring>
#include"tennis.h"

TableTennisPlayer::TableTennisPlayer(const char *fn, const char *ln, bool ht)
{
	std::strncpy(fname, fn, LIM - 1);
	fname[LIM - 1] = '\0';
	std::strncpy(lname, ln, LIM - 1);
	lname[LIM - 1] = '\0';
	hTable = ht;
}

TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer &tp)
{
	std::strncpy(fname, tp.fname, LIM - 1);
	fname[LIM - 1] = '\0';
	std::strncpy(lname, tp.lname, LIM - 1);
	lname[LIM - 1] = '\0';
	hTable = tp.hTable;
}

void TableTennisPlayer::name()const
{
	std::cout << lname << "-" << fname;
}

//member initlizer list
RatePlayer::RatePlayer(unsigned int r, const char *fn, const char *ln, bool ht):TableTennisPlayer(fn, ln, ht)
{
	rate = r;
}

//member initlizer list
RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer &tp):TableTennisPlayer(tp),rate(r)
{
	
}







