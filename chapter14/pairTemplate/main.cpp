#include<iostream>
#include<string>
#include"pair.h"

using namespace std;

int main()
{
	Pair<string, int> rank[5] = {Pair<string, int>("Java", 1), 
								 Pair<string, int>("python", 2), 
								 Pair<string, int>("c", 3), 
	                             Pair<string, int>("php", 4), 
	                             Pair<string, int>("c++", 5)};
	int joints = sizeof(rank) / sizeof(Pair<string, int>);
	cout << "Rank: \n";
	for(int i = 0; i < joints; i++)
	{
		cout << rank[i].second() << " : " << rank[i].first() << endl;
	}
	
	cout << "Ooops , new ranking appears : \n";
	rank[1].first() = "c";
	rank[2].first() = "python";
	for(int i = 0; i < joints; i++)
	{
		cout << rank[i].second() << " : " << rank[i].first() << endl;
	}
	cout << "done . " << endl;
	return 0;
}


