#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

const int Arsize = 10;

int main()
{
	double donation[Arsize];
	double item;
	int index = 0;
	double sum = 0;
	cout << "Enter a number, if not, I will exit!" << endl;
	while (cin >> item)
	{
		if (index < 10)
		{
			donation[index] = item;
			sum += item;
			index++;
			//cout << "number is : " << item << endl;
		}
		else 
		{
			break;
		}
	}

	if (index == 0)
	{
		cout << "no data read ! " << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		double ave = (sum/index);
		cout << "Average = : " << ave << endl;
		int j = 0;
		for (int i = 0; i <= index; i++)
		{
			if (donation[i] > ave)
			{
				j++;
			}
		}
		cout << "There is " << j << " numbers is greater than average." << endl;
	}
	return 0;
}

