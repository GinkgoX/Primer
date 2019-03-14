#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

const int LIM = 20;
const char *file = "plant.txt";

struct plant
{
	char name[LIM];
	double population;
	double g;
};

inline void eatline(){while(cin.get() != '\n') continue;};

int main()
{
	cout << fixed << right;
	plant pl;
	
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if(fin.is_open())
	{
		cout << "Here is the info in the " << file << endl;
		while(fin.read((char*)&pl, sizeof(pl)))
		{
			cout << setw(20) << pl.name << " : ";
			cout << setw(20) << pl.population << " : ";
			cout << setw(20) << pl.g << endl;
		}
		fin.close();
	}
	
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if(!fout.is_open())
	{
		cerr << "Could not open the file . " << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Enter the plant name (end with a blank line) : ";
	cin.get(pl.name, 20);
	while(pl.name[0] != ' ')
	{
		cout << "Enter the plantary population : ";
		cin >> pl.population;
		cout << "Enter the gravity : ";
		cin >> pl.g;
		eatline();
		fout.write((char*)&pl, sizeof(pl));
		cout << "Enter the plant name (end with a blank line) : ";
		cin.get(pl.name, 20);
	}
	fout.close();
	
	fin.open(file, ios_base::in | ios_base::binary);
	if(fin.is_open())
	{
		cout << "Here is the info in the " << file << endl;
		while(fin.read((char*)&pl, sizeof(pl)))
		{
			cout << pl.name << " : ";
			cout << setw(20) << pl.population << " : ";
			cout << setw(20) << pl.g << endl;
		}
		fin.close();
	}
	
	cout << "done . " << endl;
	return 0;
}

