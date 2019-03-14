#include<iostream>
using namespace std;
int main()
{
	int rows;
	cout << "Enter numbers of rows: ";
	cin >> rows;
		for (int i = 0 ; i < rows; i++)
		{
			for (int j = 0;j <rows - i - 1;j++)
			{
				cout << ".";
			}
			for (int k = rows - i - 1; k < rows; k++)
			{
				cout << "*";
			}
			cout << endl;
		}
	return 0;
}

