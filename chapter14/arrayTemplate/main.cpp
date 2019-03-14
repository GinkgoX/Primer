#include<iostream>
#include"array.h"

using namespace std;

int main()
{
	Array<int, 10>sum;
	Array<double, 10>ave;
	Array< Array<int, 5>, 10>twode;
	
	for(int i = 0; i < 10; i++)
	{
		sum[i] = 0;
		for(int j = 0; j < 5; j++)
		{
			twode[i][j] = (i + 1)*(j + 1);
			sum[i] += twode[i][j];
		}
		ave[i] = (double) sum[i] / 5;
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << twode[i][j] << " ";
		}
		cout << "sum = ";
		cout.width(3);
		cout << sum[i] << " , average = " << ave[i] << endl;
	}
	cout << "done . " << endl;
	return 0;
}

