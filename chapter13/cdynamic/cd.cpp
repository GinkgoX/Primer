#include<iostream>
#include<cstring>
#include"cd.h"

using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	playertime = 0.0;
}


Cd::Cd(const char *pf, const char *lb, int sl, double pt)
{
	performers = new char[strlen(pf) + 1];
	strcpy(performers, pf);
	label = new char[strlen(lb) + 1];
	strcpy(label, lb);
	selections = sl;
	playertime = pt;
}

Cd::Cd(const Cd &cd)
{
	performers = new char[strlen(cd.performers) + 1];
	strcpy(performers, cd.performers);
	label = new char[strlen(cd.label) + 1];
	strcpy(label, cd.label);
	selections = cd.selections;
	playertime = cd.playertime;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::report()const
{
	cout << "Performers : " << performers << endl;
	cout << "Label : " << label << endl;
	cout << "Selections : " << selections << endl;
	cout << "Playtime : " << playertime << endl;
	cout << endl;
}

Cd & Cd::operator=(const Cd &cd)
{
	if(this == &cd)
	{
		return *this;
	}
	delete[] performers;
	delete[] label;
	performers = new char[strlen(cd.performers) + 1];
	label = new char[strlen(cd.label) + 1];
	strcpy(performers, cd.performers);
	strcpy(label, cd.label);
	selections = cd.selections;
	playertime = cd.playertime;
	return *this;
}

Classic::Classic():Cd()
{
	works = new char[1];
	works[0] = '\0';
}

Classic::Classic(const char *wk, const char *pf, const char *lb, int sl, double pt):Cd(pf, lb, sl, pt)
{
	works = new char[strlen(wk) + 1];
	strcpy(works, wk);
}

Classic::Classic(const Classic &cs):Cd(cs)
{
	works = new char[strlen(cs.works) + 1];
	strcpy(works, cs.works);
}

Classic::~Classic()
{
	delete[] works;
}

void Classic::report()const
{
	cout << "----- Classic Info -----" << endl;
	cout << "Works : " << works << endl;
	Cd::report();
}

Classic & Classic::operator=(const Classic &cs)
{
	if(this == &cs)
	{
		return *this;
	}
	Cd::operator=(cs);
	delete[] works;
	works = new char[strlen(cs.works) + 1];
	strcpy(works, cs.works);
	return *this;
}

