#include<iostream>
#include<iomanip>	// fixed, setprecision()

using namespace std;

const int Arsize = 5;

int main()
{
	int goal[Arsize];
	double total = 0.0;
	cout << "Enter " << Arsize << " numbers for goalf scores :";
	for (int i = 0; i < Arsize; i++)
	{
		cout << "round: # " << i + 1 << ": ";
		while (!(cin >> goal[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Enter a number : ";
		}
		total += goal[i];
	}
	cout << "Average = " << fixed << setprecision(2) << (total / Arsize) << endl;
	return 0;
}


