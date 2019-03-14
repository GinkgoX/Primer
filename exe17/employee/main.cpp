#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"employee.h"

using namespace std;

const int MAX = 10;

int main()
{
	cout << "This demo is to save the multi-class object into a file " << endl;
	base_emp *pe[MAX];
	string fname;
	cout << "Enter the file name : ";
	getline(cin, fname);
	ifstream fin;
	fin.open(fname.c_str());
	if(!fin.is_open())
	{
		cout << "Could not open the file . " << endl;
		exit(EXIT_FAILURE);
	}
	
	char ch;
	int emptype;
	int i = 0;
	while(fin >> emptype)
	{
		switch(emptype)
		{
			case employee:
				pe[i] = new Employee;
				break;
			case manager:
				pe[i] = new Manager;
				break;
			case fink:
				pe[i] = new Fink;
				break;
			case highFink:
				pe[i] = new HighFink;
				break;
			default:
				cout << "Error type ";
		}
		pe[i]->readAll(fin);
		pe[i]->showAll();
		i++;
	}
	fin.close();
	
	ofstream fout;
	fout.open(fname.c_str(), ios::out | ios::app);
	int index = 0;
	cout << "Enter the class type you want to create : " << endl;
	cout << "E(employee), M(Manager), F(fink), H(highFink), Q(quit)" << endl;
	while(cin >> ch && ch != 'Q')
	{
		if(index < MAX)
		{
			cin.get();
			switch(ch)
			{
				case 'E':
				case 'e':
					pe[index] = new Employee;
					pe[index]->setAll();
					break;
				case 'M':
				case 'm':
					pe[index] = new Manager;
					pe[index]->setAll();
					break;
				case 'F':
				case 'f':
					pe[index] = new Fink;
					pe[index]->setAll();
					break;
				case 'H':
				case 'h':
					pe[index] = new HighFink;
					pe[index]->setAll();
					break;
				default:
					cout << "Error type . " << endl;
			}
			index++;
			cout << "Enter E, M, F, H, Q again " << endl;	
		}
		else
		{
			cout << "the index is of out of the array . " << endl;
			break;
		}
	}
	
	for(i = 0; i < index; i++)
	{
		pe[i]->writeAll(fout);
	}
	fout.close();
	fin.clear();
	fin.open(fname.c_str());
	cout << "Here is the refreshed file " << endl;
	while((fin >> emptype).get(ch))
	{
		switch(emptype)
		{
			case employee:
				pe[i] = new Employee;
				break;
			case manager:
				pe[i] = new Manager;
				break;
			case fink:
				pe[i] = new Fink;
				break;
			case highFink:
				pe[i] = new HighFink;
				break;
			default:
				cout << "Error type ";
		}
		pe[i]->readAll(fin);
		pe[i]->showAll();
		i++;
	}
	fin.close();
	cout << "done . " << endl;
	return 0;
}
