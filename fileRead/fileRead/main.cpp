/*
#include<iostream>
#include<fstream>		//ifstream
#include<cstdlib>		//exit(EXIT_FAILURE)
#include<iomanip>		//fixed << setprecision(3)

using namespace std;

int main()
{
	double prices;
	double sum = 0;
	int item = 0;
	ifstream inFile;
	inFile.open("price.txt");
	
	if (!inFile.is_open())
	{
		cout << "Can not open the file, program terminating !";
		exit(EXIT_FAILURE);
	}
	inFile >> prices;
	while (inFile.good())
	{
		//cout << prices << endl;
		++item;
		sum += prices;
		inFile >> prices;
	}
	if (inFile.eof())
	{
		cout << "End Of File ! ";
	}
	else if (inFile.fail())
	{
		cout << "Input Terminated by data mismatch !";
	}
	else
	{
		cout << "Input Terminated by unkonwn reasons !";
	}
	if (item == 0)
	{
		cout << "No data processed !";
	}
	else
	{
		cout << "Items: " << item <<endl;
		cout << "Total price: " << sum << endl;
		cout << "Average price: " << fixed << setprecision(2) << (sum / item) << endl;
	}
	inFile.close();
	return 0;
}
*/

