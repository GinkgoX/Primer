#include<iostream>
#include<cstring>
#include"cd.h"


using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

Cd::Cd()
{
	 strcpy(performers, "none");
	 strcpy(label, "none");
	 selections = 0;
	 playtime = 0.0;
}

Cd::Cd(const char *pf, const char *lb, int sl, double pt)
{
	strcpy(performers, pf);
	strcpy(label, lb);
	selections = sl;
	playtime = pt;
}

Cd::Cd(const Cd &cd)
{
	strcpy(performers, cd.performers);
	strcpy(label, cd.label);
	selections = cd.selections;
	playtime = cd.playtime;
}

Cd::~Cd()
{

}


void Cd::report()const
{
	cout << "Performers : " << performers << endl;
	cout << "Label : " << label << endl;
	cout << "Selections : " << selections << endl;
	cout << "Playtime : " << playtime << endl; 
	cout << endl;
}

Cd & Cd::operator=(const Cd &cd)
{
	if(this == &cd)
	{
		return *this;
	}
	strcpy(performers, cd.performers);
	strcpy(label, cd.label);
	selections = cd.selections;
	playtime = cd.playtime;
	return *this;
}

Classic::Classic():Cd()
{
	strcpy(works, "none");
}

Classic::Classic(const char *wk, const char *pf, const char *lb, int sl, double pt):Cd(pf, lb, sl, pt)
{
	strcpy(works, wk);
}

Classic::Classic(const Classic &cs):Cd(cs)
{
	strcpy(works, cs.works);
}

Classic::~Classic()
{

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
	strcpy(works, cs.works);
	return *this;
}

