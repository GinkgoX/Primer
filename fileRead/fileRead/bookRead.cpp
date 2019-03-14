#include<iostream>
#include<fstream>		//ifstream
#include<cstdlib>		//exit(EXIT_FAILURE)
#include<iomanip>		//fixed << setprecision(3)

using namespace std;

int main()
{
	char words;
	double prices = 0.0;
	double sum = 0;
	int item = 0;
	ifstream inFile;
	inFile.open("book.txt");

	if (!inFile.is_open())
	{
		cout << "Can not open the file, program terminating !";
		exit(EXIT_FAILURE);
	}
	while (inFile.good())
	{
		if ((inFile.get()) == '$')
		{
			inFile >> prices;
			sum += prices;
			item++;	
		}
		inFile.get();
	}
	if (item == 0)
	{
		cout << "No data processed !";
	}
	else
	{
		cout << "Items: " << item << endl;
		cout << "Total price: " << sum << endl;
		cout << "Average price: " << fixed << setprecision(2) << (sum / item) << endl;
	}
	inFile.close();
	return 0;
}

