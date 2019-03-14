#include<iostream>
#include"persion.h"

using namespace std;

const int SIZE = 5;

int main()
{
	Persion *pes[SIZE];
	char ch;
	
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Enter person catelogy: G(Gunslinger), P(PokerPlayer), B(BadDude), or Q(Quit)" << endl;
		cin >>ch; 
		if((ch == 'Q') || (ch == 'q'))
		{
			break;
		}
		switch(ch)
		{
			case 'G':
			case 'g':
						pes[i] = new Gunslinger;
						break;
			case 'P':
			case 'p':
						pes[i] = new PokerPlayer;
						break;
			case 'B':
			case 'b':
						pes[i] = new BadDude;
						break;
			default:
						cout << "Only G(Gunslinger), P(PokerPlayer), B(BadDude), Q(quit) is avaiable , Please try again ! " << endl;	
		}
		cin.get();
		pes[i]->set();
	}
	
	cout << "The Persion Info as follows : " << endl;
	for(int i = 0; i < SIZE; i++)
	{
		pes[i]->show();
		cout << endl;
	}
	for(int i = 0; i < SIZE; i++)
	{
		delete pes[i];
	}
	cout << "done . " << endl;
	return 0;
}





