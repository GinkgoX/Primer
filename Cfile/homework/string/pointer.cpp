#include<iostream>
#include<cstdlib>
#include<ctime>
#include"strg.h"

const int Arsize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << "Hi, what's your name ?\n";
	cin >> name;
	cout << name <<", enter " << Arsize << " short saying you like(empty line to quit):\n";
	String saying[Arsize];
	char temp[MaxLen];
	int i;
	for(i = 0; i < Arsize; i++)
	{
		cout << i + 1 << " : ";
		cin.get(temp, MaxLen);
		while(cin && (cin.get() != '\n'))
		{
			continue;
		}
		if(!cin || (temp[0] == '\0'))
		{
			break;
		}
		else
		{
			saying[i] = temp;
		}
	}
	int total = i;
	if(total > 0)
	{
		cout << "Here is the short saying you like: \n";
		for(i = 0; i < total; i++)
		{
			cout << saying[i] << endl;
		}
	
		String *shorest = &saying[0];
		String *first = &saying[0];
		for(i = 1; i < total; i++)
		{
			if(saying[i].length() < shorest->length())
			{
				shorest = &saying[i];
			}
			if(saying[i] < *first)
			{
				first = &saying[i];
			}
		}
		cout << "Shortest saying is : " << *shorest << endl;
		cout << "First saying is : " << *first << endl;
		
		srand(time(0));
		int choise = rand() % total;
		String *favorite = new String(saying[choise]);
		cout << "your favorite choise is : " << *favorite << endl;
		delete favorite;
	}
	else
	{
		cout << "No much to say, eh? " << endl;
	}	
	cout << "Bye ." << endl;
	return 0;
} 

