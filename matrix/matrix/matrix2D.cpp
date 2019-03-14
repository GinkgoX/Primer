#include<iostream>

using namespace std;

int main()
{
	const int Cities = 5;
	const int Years = 4;

	const char* cities[Cities] = { "BeiJing","Shanghai","Guangzhou","Nanjing","Wuhan" };
	int maxWage[Years][Cities] = { {8,9,8,8,7}, {9,8,7,7,6}, {8,7,7,6,7}, {7,8,8,8,6}};

	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << " : \t";
		for (int year = 0; year < Years; ++year)
		{
			cout << maxWage[year][city] << " ";
		}
		cout << endl;
	}
	return 0;
}










