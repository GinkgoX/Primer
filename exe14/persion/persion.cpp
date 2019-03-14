#include<iostream>
#include<cstdlib>
#include"persion.h"

using std::cout;
using std::endl;
using std::cin;

Persion::~Persion()
{

}

void Persion::data()const
{
	cout << "Name info : " << fname << " " << lname << endl;
}

void Persion::get()
{
	cout << "Enter the first name : ";
	getline(cin, fname);
	cout << "Enter the last name : ";
	getline(cin, lname);
} 

void Persion::show()const
{
	data();
}

void Persion::set()
{
	get();
}

void Gunslinger::data()const
{
	cout << "Nicks info : " << nicks << endl;
	cout << "Time for gun getting : " << Gunslinger::draw() << endl;
}

void Gunslinger::get()
{
	cout << "Enter nicks : ";
	cin >> nicks;
}

void Gunslinger::show()const
{
	Persion::data();
	data();
}

void Gunslinger::set()
{
	Persion::get();
	get();
}

double Gunslinger::draw()const
{
	return rand() % 3 + 1 ;
}

void PokerPlayer::data()const
{
	cout << "Card info : " << draw() << endl;
}

void PokerPlayer::show()const
{
	Persion::data();
	data();
}

int PokerPlayer::draw()const
{
	return rand() % 52 + 1;
}

void BadDude::data()const
{
	Gunslinger::data();
	PokerPlayer::data();
	cout << "the new card info : " << cDraw() << endl;
	cout << "the baddude gun getting time : " << gDraw() << endl;
}

void BadDude::get()
{
	Gunslinger::get();
}

void BadDude::set()
{
	Persion::get();
	get();
}

void BadDude::show()const
{
	Persion::data();
	data();
}

int BadDude::cDraw()const
{
	return PokerPlayer::draw();
}

double BadDude::gDraw()const
{
	return Gunslinger::draw();
}

