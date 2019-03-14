#include<iostream>
#include"strg.h"

const int Arsize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << "Hi, what's your name ? ";
	cin >> name;
	cout << name << " , please enter " << Arsize << " short saying (q or Q to quit):" << endl;
	String saying[Arsize];
	char temp[MaxLen];
	int i;
	for(i = 0; i < Arsize; i++)
	{
		cout << i + 1 << " : ";
		cin.get(temp, MaxLen);
		while(cin && cin.get() != '\n')
		{
			continue;
		}
		if(!cin || temp[0] == '\n')
		{
			break;
		}
		else
		{
			saying[i] = temp;
		}
	}
	
	int total = i;
	cout << "Here are your  saying : \n";
	for(i = 0; i < total; i++)
	{
		cout << saying[i][0] << " : " << saying[i] << endl;
	}
	
	int shortest = 0;
	int first = 0;
	for(i = 1; i < total; i++)
	{
		if(saying[i].length() < saying[shortest].length())
		{
			shortest = i;
		}
		if(saying[i] < saying[first])
		{
			first = i;
		}
	}
	
	cout << "shortest saying : \n" << saying[shortest] << endl;
	cout << "first alphabetically : \n" << saying[first] << endl;
	cout << "this program used " << String::count() << " string obiects ." << endl;
	
	return 0;
}
