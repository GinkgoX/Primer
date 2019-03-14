#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

const int LIM  = 20;
const char *file = "plant.txt";
inline void eatline(){while(cin.get() != '\n') continue;};

struct plant
{
	char name[LIM];
	double population;
	double g;
};

int main()
{
	cout << fixed << right;
	plant pl;
	
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if(finout.is_open())
	{
		finout.seekg(0);
		cout << "Here is the current contents of " << file << endl;
		while(finout.read((char*)&pl, sizeof(pl)))
		{
			cout << ct++ << " : " << setw(20) << pl.name;
			cout << setprecision(0) << setw(20) << pl.population << " : ";
			cout << setprecision(2) << setw(20) << pl.g << endl; 
		}
		if(finout.eof())
		{
			finout.clear();
		}
		else
		{
			cerr << "Error in reading the file ." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "Could not open the file ." << endl;
		exit(EXIT_FAILURE);
	}
	
	cout << "Enter the record number you want to change : ";
	int record;
	cin >> record;
	eatline();
	while(record < 0 && record >= ct)
	{
		cerr << "Error on attempted seek ." << endl;
		exit(EXIT_FAILURE);
	}
	
	streampos place = record * sizeof(pl);
	finout.seekg(place);
	if(finout.fail())
	{
		cerr << "Error on attempted seek ." << endl;
		exit(EXIT_FAILURE);
	}
	
	finout.read((char*)&pl, sizeof(pl));
	cout << "Your selection : " << endl;
	cout << record << " : " << setw(20) << pl.name;
	cout << setprecision(0) << setw(20) << pl.population;
	cout << setprecision(2) << setw(20) << pl.g << endl;
	if(finout.eof())
	{
		finout.clear();
	}
	
	cout << "Enter the plant name :" ;
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter the plantary population : ";
	cin >> pl.population;
	cout << "Enter the gravity : ";
	cin >> pl.g;
	finout.seekp(place);
	finout.write((char*)&pl, sizeof(pl)) << flush;
	if(finout.fail())
	{
		cerr << "Error on attempted seek . " << endl;
		exit(EXIT_FAILURE);
	}
	ct = 0;
	finout.seekg(0);
	cout << "Here is the new contents in " << file << endl;
	while(finout.read((char*)&pl, sizeof(pl)))
	{
		cout << ct++ << " : " << setw(20) << pl.name;
		cout << setprecision(0) << setw(20) << pl.population;
		cout << setprecision(2) << setw(20) << pl.g << endl;
		
	}
	finout.close();
	cout << "done . " << endl;
	return 0;
}





