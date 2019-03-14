#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

const char *file = "guests.txt";

using namespace std;

int main()
{
	char ch;
	string str;
	ifstream fin;
	fin.open(file);
	if(fin.is_open())
	{
		cout << "The current iofo in " << file << endl;
		while(fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
	
	ofstream fout(file, ios::out | ios::app);
	if(!fout.is_open())
	{
		cerr << "Could not open the file . " << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Enter the guests name (quit to exit): ";
	string name;
	long id;
	while(getline(cin, name) && name.size() > 0)
	{
		if(name == "quit")
		{
			break;
		}
		else
		{
			fout << "Name : " << name << endl;
			cout << "Enter the the guests ID : ";
			cin >> id;
			fout << "ID : " << id << endl;
			cin.get();
			cout << "Enter the guests name (quit to exit): ";
		}
	}
	fout.close();
	
	cout << "done . " << endl;
	return 0;
}

